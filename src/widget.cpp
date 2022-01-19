#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
//    setAttribute(Qt::WA_TranslucentBackground);
    //    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setMouseTracking(true);
//    ui->tabMain->setMouseTracking(true);
//    ui->gbStatusBar->setMouseTracking(true);
    ui->gbTitle->setMouseTracking(true);
//    hk_helper = new HKHelper(this);
//    hk_helper->play_custom("192.168.1.30",8000,"admin","xiao123456");
//    connect(hk_helper,&HKHelper::decode_image_cv,[](cv::Mat img){
//       qDebug()<<"--------------";
//    });
}



Widget::~Widget()
{
    delete ui;
}

// 切换视频预览tab页 其中两个按钮为toolBotton,所以可以设置选中状态与tab相联动
void Widget::on_tbPreview_clicked()
{
    ui->tbPreview->setChecked(true);
    ui->tbSetting->setChecked(false);
    ui->tabMain->setCurrentIndex(0);
}

// 切换设置tab页
void Widget::on_tbSetting_clicked()
{
    ui->tbPreview->setChecked(false);
    ui->tbSetting->setChecked(true);
    ui->tabMain->setCurrentIndex(1);
}



void Widget::on_tbMinium_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}


void Widget::on_tbMaxium_clicked()
{
    if(this->windowState()==Qt::WindowMaximized){
        ui->tbMaxium->setIcon(QIcon(":/images/maxium.png"));
        ui->tbMaxium->setToolTip("最大化");
        this->showNormal();
        return;
    }
    else if(this->windowState()==Qt::WindowNoState){
        ui->tbMaxium->setIcon(QIcon(":/images/normal.png"));
        ui->tbMaxium->setToolTip("恢复");
        this->setWindowState(Qt::WindowMaximized);
    }
}


void Widget::on_tbClose_clicked()
{
    int ret = QMessageBox::warning(this,"警告","确定关闭软件？",QMessageBox::Ok,QMessageBox::Cancel);
    if(ret == QMessageBox::Ok){
        this->close();
    }
}

void Widget::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(ui->gbTitle->geometry().contains(this->mapFromGlobal(QCursor::pos())))
    {
        if(this->isMaximized())
        {
            this->showNormal();
            /*TODO一些其他需要处理的事情*/
        }
        else
        {
            this->showMaximized();
            /*TODO一些其他需要处理的事情*/
        }
    }
    else
    {
        Widget::mouseDoubleClickEvent(e);
    }
}
#if 1

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPosition() - frameGeometry().topLeft();
        QRect rect = ui->gbTitle->rect();
        if(rect.contains(event->pos()))
        {
            mMoveable = true;
        }
        event->accept();
    }
}


void Widget::mouseMoveEvent(QMouseEvent *event)
{

    if((event->buttons() == Qt::LeftButton) && mMoveable &&!(this->windowState()==Qt::WindowMaximized))
    {
        QPointF currentPointF = event->globalPosition() - dragPosition;
        this->move(currentPointF.x(),currentPointF.y());
        // 窗口重绘，相当之重要
        this->update();
        event->accept();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    if(mMoveable)
    {
        mMoveable = false;
    }
}

#endif
#if 0
Widget::MousePoss Widget::calcMousePoss(QPoint p)
{
    MousePoss mp;
    if(p.x()<MOUSE_MARGIN && p.y() < MOUSE_MARGIN)
        mp=MousePoss::LeftUp;   //左上
    else if(p.x()>MOUSE_MARGIN && p.y()< MOUSE_MARGIN && p.x()<this->width()-MOUSE_MARGIN)
        mp = MousePoss::Up;   //上
    else if(p.x() > this->width()-MOUSE_MARGIN && p.y() < MOUSE_MARGIN)
        mp = MousePoss::RightUp;   //右上
    else if(p.x() > this->width()-MOUSE_MARGIN && p.y() > MOUSE_MARGIN && p.y()<this->height()-MOUSE_MARGIN)
        mp = MousePoss::Right;   //右
    else if(p.x() > this->width()-MOUSE_MARGIN && p.y() > this->height()-MOUSE_MARGIN)
        mp = MousePoss::RightDown;   //右下
    else if(p.x()>MOUSE_MARGIN && p.x() < this->width()-MOUSE_MARGIN && p.y() > this->height()-MOUSE_MARGIN)
        mp = MousePoss::Down;   //下
    else if(p.x() < MOUSE_MARGIN && p.y() > this->height()-MOUSE_MARGIN)
        mp = MousePoss::LeftDown;   //左下
    else if(p.x() < MOUSE_MARGIN && p.y() < this->height()-MOUSE_MARGIN && p.y()>MOUSE_MARGIN)
        mp = MousePoss::Left;   //左
    else
        mp=MousePoss::Middle;   //中间
    return mp;
}
//修改鼠标样式
void Widget::setCursorType(MousePoss type)
{
    Qt::CursorShape cursor;
    switch(type)
    {
    case MousePoss::LeftUp:
    case MousePoss::RightDown:
        cursor=Qt::SizeFDiagCursor;
        break;
    case MousePoss::Up:
    case MousePoss::Down:
        cursor=Qt::SizeVerCursor;
        break;
    case MousePoss::RightUp:
    case MousePoss::LeftDown:
        cursor=Qt::SizeBDiagCursor;
        break;
    case MousePoss::Right:
    case MousePoss::Left:
        cursor=Qt::SizeHorCursor;
        break;
    default:
        cursor=Qt::ArrowCursor;
        break;
    }
    setCursor(cursor);
}
//改变窗口的大小
void Widget::changeWindowSize(MousePoss type, QRect &wid,QPoint ptemp,int minWidth, int minHeight)
{
    switch(type)//改变窗口的大小
    {
    case MousePoss::LeftUp:
    {
        QPoint pos = wid.topLeft();

        if(wid.width() > minWidth || ptemp.x() < 0)
            pos.rx() = pos.rx() + ptemp.x();
        if(wid.height() > minHeight || ptemp.y() < 0)
            pos.ry() = pos.ry() + ptemp.y();

        wid.setTopLeft(pos);
        break;//左上角
    }
    case MousePoss::RightUp:
    {
        QPoint pos = wid.topRight();

        if(wid.width() > minWidth || ptemp.x() > 0)
            pos.rx() = pos.rx() + ptemp.x();
        if(wid.height() > minHeight || ptemp.y() < 0)
            pos.ry() = pos.ry() + ptemp.y();

        wid.setTopRight(pos);
        break;//右上角
    }
    case MousePoss::LeftDown:
    {
        QPoint pos = wid.bottomLeft();

        if(wid.width() > minWidth || ptemp.x() < 0)
            pos.rx() = pos.rx() + ptemp.x();
        if(wid.height() > minHeight || ptemp.y() > 0)
            pos.ry() = pos.ry() + ptemp.y();

        wid.setBottomLeft(pos);
        break;//左下角
    }
    case MousePoss::RightDown:
    {
        QPoint pos = wid.bottomRight();

        if(wid.width() > minWidth || ptemp.x() > 0)
            pos.rx() = pos.rx() + ptemp.x();
        if(wid.height() > minHeight || ptemp.y() > 0)
            pos.ry() = pos.ry() + ptemp.y();

        wid.setBottomRight(pos);
        break;//右下角
    }
    case MousePoss::Up:
    {
        int topY = wid.top();
        if(wid.height() > minHeight || ptemp.y() < 0)
            topY = topY + ptemp.y();

        wid.setTop(topY);
        break;//上
    }
    case MousePoss::Left:
    {
        int leftX = wid.left();

        if(wid.width() > minWidth || ptemp.x() < 0)
            leftX = leftX + ptemp.x();

        wid.setLeft(leftX);
        break;//左
    }
    case MousePoss::Right:
    {
        int rightX = wid.right();

        if(wid.width() > minWidth || ptemp.x() > 0)
            rightX = rightX + ptemp.x();

        wid.setRight(rightX);
        break;//右
    }
    case MousePoss::Down:
    {
        int botY = wid.bottom();
        if(wid.height() > minHeight || ptemp.y() > 0)
            botY = botY + ptemp.y();

        wid.setBottom(botY);
        break;//下
    }
    default:
        break;
    }
}

//三个鼠标事件的重写
void Widget::mousePressEvent(QMouseEvent *e)
{

    if(e->button()== Qt::LeftButton)	//鼠标左键按下
    {
        last = e->globalPos();
        e->ignore();
    }


}
//鼠标移动
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    //最大化状态，鼠标是否在标题栏,拖拽还原
    if(this->isMaximized())
    {
        if(ui->gbTitle->geometry().contains(this->mapFromGlobal(QCursor::pos())) && e->buttons()==Qt::LeftButton)
        {
            QPoint ptemp=e->globalPos();
            if(ptemp!=last)
            {
                this->showNormal();
            }
        }
    }
    MousePoss curPos=calcMousePoss(e->pos());
    if(!e->buttons())
    {
        setCursorType(curPos);
        mCurPos=curPos;
    }

    if(e->buttons()==Qt::LeftButton)	//坐标左键按下并移动
    {
        QPoint ptemp=e->globalPos();
        ptemp=ptemp-last;  //鼠标移动的偏移量
        if(mCurPos==MousePoss::Middle && ui->gbTitle->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            move(ptemp+pos());
        }
        else
        {
            QRect wid=geometry();
            int minWidth = this->minimumWidth();
            int minHeight = this->minimumHeight();
            changeWindowSize(mCurPos,wid,ptemp,minWidth,minHeight);
            //更新大小
            setGeometry(wid);
        }
        last = e->globalPos();
    }
    e->ignore();
}
//鼠标释放
void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton && ui->gbTitle->geometry().contains(this->mapFromGlobal(QCursor::pos())))	//鼠标左键释放
    {
        int dx = e->globalX() - last.x();
        int dy = e->globalY() - last.y();
        move(x()+dx, y()+dy);
    }
    QApplication::restoreOverrideCursor();//恢复鼠标指针性状
    e->ignore();
}
#endif







