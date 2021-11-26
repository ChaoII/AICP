#include "previewframe.h"
#include "ui_previewframe.h"
#include <QMenu>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QCamera>
#include <QMediaCaptureSession>
PreviewFrame::PreviewFrame(QWidget *parent): QWidget(parent), ui(new Ui::PreviewFrame)
{
    ui->setupUi(this);
    // 自定义QStandardItemModel类，通过xml文件读取treeModel
    xmlModel = new CustomTreeModel(this);
    // 隐藏表头。。。其中树控件只让两层（除去root节点的其它功能节点）
    ui->treeView->setHeaderHidden(true);
    // treeView 绑定model
    ui->treeView->setModel(xmlModel);
    // 不让双击编辑等操作
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 初始化treeView，从xml文件中加载QStandardItemModel
    initTreeView();
    // 默认树控件节点全部展开
    ui->treeView->expandAll();
    // 默认实例化窗体窗体切分选项对象
    windowCut = new WindowCut;
    this->setAttribute(Qt::WA_DeleteOnClose,true);

}

void PreviewFrame::initTreeView()
{
    // 通过xml文件加载model
    //    xmlModel->readFile("D:/QtCreatorProjects/treeviewTest/school.xml");
    xmlModel->CreateModelFromDBFile("ICP.db");
    dh_ = xmlModel->getDbHelper();
}

// 递归的方式进行节点删除
void PreviewFrame::removeNode(QStandardItem * item)
{
    if(item->hasChildren())
    {
        // 获取选中节点下的所有子节点删除
        for(int i = 0;i < item->rowCount() ;i++)
        {
            QStandardItem * childitem = item->child(i);
            qDebug()<<"123";
            if(xmlModel->saveRemoveResult(childitem)){
                removeNode(childitem);
            }
            else return;
        }
    }
    // 如果删到根节点直接将第一个节点（根节点）删除
    if(item->parent()==nullptr){
        xmlModel->removeRow(0);
    }
    // 如果选中的节点没有child,那么直接删除该节点
    else{
        if(xmlModel->saveRemoveResult(item)){
            item->parent()->removeRow(xmlModel->indexFromItem(item).row());
        }
    }
}

// 获取当前可用的窗体显示窗体界面，目前窗体界面为支持最多9个,总是选用未被占用的最小编号的窗体
int PreviewFrame::getLabelIndex()
{
    // 将labelListIndex进行从小到大的排序
    std::sort(labelListIndex.begin(),labelListIndex.end());
    // 如果list为空说明窗体已经被用完了，那么从新按0-9分配窗体
    if(labelListIndex.empty()) labelListIndex ={0,1,2,3,4,5,6,7,8,9};
    // 获取最小编号窗体作为新的摄像头画面显示窗体
    int index = labelListIndex[0];
    // 在列表中删掉已经被用的窗体编号
    labelListIndex.pop_front();
    return index;
}

void PreviewFrame::getAllCameraInfo(QStandardItem * item)
{
    if(item->hasChildren())
    {
        // 获取选中节点下的所有子节点删除
        for(int i = 0;i < item->rowCount();i++)
        {
            QStandardItem * childitem = item->child(i);
            if(childitem->whatsThis()=="camera"){               // 从对象中取出绑定的cmera对象
                Camera* camera = childitem->data().value<Camera*>();
                QString key =item->text();
                // 如果camera已经被开启，那么返回
                if(camera->getStartStatus()) return;
                // 获取当前摄像头显示的label编号
                labelIndex=getLabelIndex();
                // 将label与当前camer对象绑定
                camera->setShowLabelindex(labelIndex);
                // 开启线程
                CameraShowThread* thread =new CameraShowThread(*camera);
                // 打包camer对象与对应的线程对象（如果在camera对象中增加线程属性，那么即陷入循环引用的窘境，需要后续优化程序结构）
                CameraStruct cameraStruct{camera,thread};
                // 将camera 对象及对应的线程进存储 在map中，key用camera名称
                cameraMap.insert(camera->getName(),cameraStruct);
            }
            getAllCameraInfo(childitem);
        }

    }
}


PreviewFrame::~PreviewFrame()
{
    if (!(windowCut==nullptr)){
        delete windowCut;
        windowCut = nullptr;
    }
    delete ui;
}

void PreviewFrame::keyPreddEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Escape && windowCut->isVisible()){
        windowCut->setVisible(false);
        event->accept();
    }
}

void PreviewFrame::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton && windowCut->isVisible()){
        windowCut->setVisible(false);
        event->accept();
    }
}

void PreviewFrame::paintEvent(QPaintEvent *event)
{
    if (windowCut->isVisible()){
        QPoint globalPos=ui->tbCutWindow->mapToGlobal(QPoint(0,0));
        windowCut->move( globalPos.x()+ui->tbCutWindow->width()-windowCut->width(), globalPos.y()-windowCut->height());
    }
    return QWidget::paintEvent(event);
}


// 双击播放视频
void PreviewFrame::on_treeView_doubleClicked(const QModelIndex &index)
{
    // 获取当前双击的item对象
    QStandardItem * item = xmlModel->itemFromIndex(index);
    // 从对象中取出绑定的cmera对象
    Camera* camera = item->data().value<Camera*>();
    QString key =item->text();
    // 如果camera已经被开启，那么返回
    if(camera->getStartStatus()) return;
    // 获取当前摄像头显示的label编号
    labelIndex=getLabelIndex();
    // 将label与当前camer对象绑定
    camera->setShowLabelindex(labelIndex);
    // 开启线程
    CameraShowThread* thread =new CameraShowThread(*camera);
    // 打包camer对象与对应的线程对象（如果在camera对象中增加线程属性，那么即陷入循环引用的窘境，需要后续优化程序结构）
    CameraStruct cameraStruct{camera,thread};
    // 自定西信号和槽函数将子线程中的img发送法主线程
    connect(thread,&CameraShowThread::imageShowFinished,this,&PreviewFrame::on_processCapturedImage,Qt::BlockingQueuedConnection);
    // 线程返回后直接关闭线程
    connect(thread,&QThread::finished ,thread,&QObject::deleteLater);
    // 开启对应线程
    thread->start();
    // 将摄像头状态设置为开启
    camera->setStartStatus(true);
    // 将camera 对象及对应的线程进存储 在map中，key用camera名称
    cameraMap.insert(camera->getName(),cameraStruct);
}


void PreviewFrame::on_treeView_customContextMenuRequested(const QPoint &pos)
{
    // camera类型的item右键菜单
    Q_UNUSED(pos);
    QMenu menue;
    QStringList qss;
    qss.append("QMenu{background-color:#303030;color:#F0F0F0}");
    qss.append("QMenu:pressed{color:555555;}");
    qss.append("QMenu:disabled{color:#b0b0b0;}");
    menue.setStyleSheet(qss.join(""));
    menue.setAttribute(Qt::WA_DeleteOnClose);
    QModelIndex index = ui->treeView->currentIndex();
    // 如果未选中item直接返回
    if(index.isValid()){
        QStandardItem* item = xmlModel->itemFromIndex(index);
        // item类型未摄像头：
        if(item->whatsThis()=="camera"){
            menue.addAction(ui->actionPlay);
            menue.addAction(ui->actionStop);
            menue.addAction(ui->actionDelete);
        }
        // item 类型为区域area
        else {
            menue.addAction(ui->actionAdd);
            menue.addAction(ui->actionDelete);
        }
        menue.exec(QCursor::pos());
    }
}
// 添加节点
void PreviewFrame::on_actionAdd_triggered()
{
    QModelIndex index = ui->treeView->currentIndex();
    // 选中节点
    if (index.isValid()){
        QStandardItem *item = xmlModel->itemFromIndex(index);
        // 选中区域节点
        if (item->whatsThis()=="area"){
            // 打开对话框，输入节点信息，封装撑camera对象
            CameraDetailDialog *dig = new CameraDetailDialog;
            // 信息完成后绑定执行该方法
            connect(dig,&CameraDetailDialog::sendCameraDetail,[=](Camera* camera){

                QString cameraName = camera->getName();
                QIcon ico(":/images/IPCamera.png");
                QStandardItem * childItem = new QStandardItem(ico,cameraName);
                // 设置节点类型
                childItem->setWhatsThis("camera");
                // 调整节点图标
                if (camera->getCameraType()==CameraType::USBCamera){
                    childItem->setIcon(QIcon(":/images/USBCamera.png"));
                }
                // item与camera对象进行绑定
                childItem->setData(QVariant::fromValue(camera));
                // 增加节点
                if (!(xmlModel->saveCameraNode(item,childItem))) return;
                item->appendRow(childItem);
            });
            dig->exec();
        }
        // 如果选定的节点是root节点（该action不会在camera节点上出现）那么新增一个area节点
        else{
            QString areaName= QInputDialog::getText(this,"添加区域","区域名称：");
            if(areaName.isEmpty()){
                QMessageBox::warning(this,"警告","区域名称不能为空");
                return;
            }
            QStandardItem * childItem = new QStandardItem(QIcon(":/images/area.png"),areaName);
            childItem->setWhatsThis("area");
            item->appendRow(childItem);
        }
    }
    // 未选中节点的情况
    else{
        QMessageBox::warning(this,"警告","请选择节点");
        return;
    }
}

void PreviewFrame::on_actionDelete_triggered()
{
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;
    QStandardItem *item = xmlModel->itemFromIndex(index);
    auto res = QMessageBox::warning(this,"警告","确定删除该节点？请详细检查当前选中的节点，节点名称:"+item->text());
    if (res==QMessageBox::Ok) {
        if (xmlModel->itemFromIndex(index)->whatsThis()=="camera")
        {
            on_actionStop_triggered();
        }
        removeNode(item);
    };
}

void PreviewFrame::on_processCapturedImage(const QImage &img,int labelIndex)
{
    QLabel *label= ui->videoPanel->getLabelPanel().at(labelIndex);
    QImage scaledImage = img.scaled(label->size(),
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation
                                    );
    label->setPixmap(QPixmap::fromImage(scaledImage));
}


void PreviewFrame::on_actionPlay_triggered()
{
    QStandardItem * item = xmlModel->itemFromIndex(ui->treeView->currentIndex());
    QString key =item->text();
    Camera* camera = item->data().value<Camera*>();
    if(camera->getStartStatus()) return;
    labelIndex=getLabelIndex();
    camera->setShowLabelindex(labelIndex);
    CameraShowThread* thread =new CameraShowThread(*camera);
    CameraStruct cameraStruct{camera,thread};
    cameraMap.insert(camera->getName(),cameraStruct);
    connect(thread,&CameraShowThread::imageShowFinished,this,&PreviewFrame::on_processCapturedImage,Qt::BlockingQueuedConnection);
    connect(thread,&QThread::finished ,thread,&QObject::deleteLater);
    thread->start();
    camera->setStartStatus(true);
}


void PreviewFrame::on_actionStop_triggered()
{
    QStandardItem * item = xmlModel->itemFromIndex(ui->treeView->currentIndex());
    QString key =item->text();
    Camera* camera = item->data().value<Camera*>();
    if (!(camera->getStartStatus())) {
        //        delete camera;
        return;
    }
    labelListIndex.push_back(camera->getShowLabelIndex());
    camera->setStartStatus(false);
    cameraMap[key].cameraShowThread->on_stop_show_video();
    cameraMap.remove(key);
    //    delete cameraMap[key].camera;
    //    delete cameraMap[key].cameraShowThread;
}

void PreviewFrame::on_tbFullScreen_clicked()
{
    if(windowCut->isVisible()) windowCut->setVisible(false);
    ui->videoPanel->setWindowFlags(Qt::Window);
    ui->videoPanel->showFullScreen();
}


void PreviewFrame::on_tbCutWindow_clicked()
{
    QPoint globalPos=ui->tbCutWindow->mapToGlobal(QPoint(0,0));
    windowCut->move( globalPos.x()+ui->tbCutWindow->width()-windowCut->width(), globalPos.y()-windowCut->height());
    if(windowCut->isVisible()){
        windowCut->setVisible(false);
    }
    else{
        windowCut->show();
    }
    connect(windowCut,&WindowCut::windowCutStatusIndex,[=](int index){
        switch (index)
        {
        case 1:
            ui->videoPanel->changeWindowCut1();
            break;
        case 4:
            ui->videoPanel->changeWindowCut4();
            break;
        case 6:
            ui->videoPanel->changeWindowCut6();
            break;
        case 9:
            ui->videoPanel->changeWindowCut9();
            break;
        }

    });
}

void PreviewFrame::on_tbOpenAll_clicked()
{
    getAllCameraInfo(xmlModel->item(0,0));
    if (cameraMap.isEmpty()) return;
    for(QString key:cameraMap.keys()){
        //        qDebug()<<key;
        //cameraMap[key] 这种写法可能会存在意想不到的风险
        if(!(cameraMap[key].camera->getStartStatus())){
            connect(cameraMap[key].cameraShowThread,&CameraShowThread::imageShowFinished,this,&PreviewFrame::on_processCapturedImage,Qt::BlockingQueuedConnection);
            connect(cameraMap[key].cameraShowThread,&QThread::finished ,cameraMap[key].cameraShowThread,&QObject::deleteLater);
            cameraMap[key].cameraShowThread->start();
            cameraMap[key].camera->setStartStatus(true);
        }
    }
}


void PreviewFrame::on_tbCloseAll_clicked()
{
    if (cameraMap.isEmpty()) return;
    for(QString key:cameraMap.keys()){
        //        qDebug()<<key;
        //cameraMap[key] 这种写法可能会存在意想不到的风险
        if(cameraMap[key].camera->getStartStatus()){
            labelListIndex.push_back(cameraMap[key].camera->getShowLabelIndex());
            cameraMap[key].camera->setStartStatus(false);
            cameraMap[key].cameraShowThread->on_stop_show_video();
            cameraMap.remove(key);
        }
    }

}

