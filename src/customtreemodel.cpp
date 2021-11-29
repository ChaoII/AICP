#include "customtreemodel.h"

CustomTreeModel::CustomTreeModel(QObject *parent) : QStandardItemModel(parent)
{

}

void CustomTreeModel::CreateModelFromDBFile(const QString& fileName)
{
    dh = new DbHelper;
    dh->initDB(fileName);
    addSubNode("-1",this->invisibleRootItem());
}

void CustomTreeModel::addSubNode(const QString &parentID, QStandardItem *item)
{
    QString sqlString = QString("select id,name,node_type from camera_tree where parent_id='%1'").arg(parentID);
    bool OK;
    QSqlQuery query= dh->execSelect(sqlString,OK);
    if(!OK) return;
    while(query.next()){
        QVariant camera_info;
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString nodeType = query.value(2).toString();
        QString IconString = ":/images/area.png";
        if(nodeType=="camera"){
            QString cameraSql=QString("select name,camera_type,camera_band,ip,port,user_name,password,item_id from camera where item_id = '%1'").arg(id);
            bool isOk;
            qDebug()<<"初始化摄像头查询：" <<cameraSql;
            QSqlQuery subQuery =dh->execSelect(cameraSql,isOk);
            if(!isOk) return;
            Camera* camera = bindCamerainfo(subQuery);
            camera_info = QVariant::fromValue(camera);
            if(camera->getCameraType()==CameraType::IPCamera){
                IconString=":/images/IPCamera.png";
            }
            else{
                IconString=":/images/USBCamera.png";
            }
        }
        else{
            camera_info = QVariant::fromValue(id);
        }
        QStandardItem *childItem = new QStandardItem(QIcon(IconString), name);
        childItem->setWhatsThis(nodeType);
        childItem->setData(camera_info);
        item->appendRow(childItem);
        addSubNode(id,childItem);
    }
}


DbHelper *CustomTreeModel::getDbHelper()
{
    return dh;
}

Camera *CustomTreeModel::bindCamerainfo(QSqlQuery & subQuery)
{
    Camera * camera = new Camera;
    subQuery.next();
    QString camera_name = subQuery.value(0).toString();
    QString camera_type = subQuery.value(1).toString();
    QString camera_band = subQuery.value(2).toString();
    QString camera_ip = subQuery.value(3).toString();
    int port = subQuery.value(4).toInt();
    QString user_name = subQuery.value(5).toString();
    QString password = subQuery.value(6).toString();
    QString item_id = subQuery.value(7).toString();
    qDebug()<<"绑定摄像头信息："<<camera_name<<camera_type<<camera_band<<camera_ip<<port<<user_name<<password<<item_id;
    camera->setIPCamera(camera_name,camera_ip,port,user_name,password,camera_type,camera_band,item_id);
    if(camera->getCameraType()==CameraType::USBCamera){
        camera->setCurrentCameraIndex(camera_band.toInt());
    }
    return camera;
}
///
/// \brief CustomTreeModel::saveCameraNode 添加节点，在数据库中保存节点信息及节点绑定设备信息
/// \param parentitem 父节点
/// \param item 当前节点
/// \return 是否保存成功
///
bool CustomTreeModel::saveCameraNode(QStandardItem*  parentitem,QStandardItem*  item){

    if(item->whatsThis()=="camera"){

        Camera* camera = item->data().value<Camera*>();
        QString item_id = camera->getItemID();
        QString item_name = camera->getName();
        // 如果数据库已经存在该节点，则添加节点失败
        if(isInDataBase(item_name)){
            qDebug()<<"数据库已经存在该节点，请勿重复添加";
            return false;
        }
        QString item_type = "camera";
        QString parent_id = parentitem->data().toString();
        QString sqlStr = QString("insert into camera_tree values('%1','%2','%3','%4')").arg(item_id,item_name,parent_id,item_type);
        // 如果插入失败，添加节点失败
        if(!(dh->execInsert(sqlStr))) {
            qDebug()<<"节点数据保存失败！！";
            return false;
        };
        QString camera_id = QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
        int camera_type = camera->getCameraType();
        int camera_band = camera->getCameraBand();
        if(camera_type == CameraType::USBCamera){
            camera_band = camera->getCurrentCameraIndex();
        }
        QString ip = camera->getIP();
        int port =camera->getPort();
        QString user_name = camera->getUserName();
        QString password = camera->getPassword();
        QString insert_str = QString("insert into camera values ('%1','%2','%3','%4','%5','%6','%7','%8',"
                                     "'%9')").arg(camera_id).arg(item_name).arg(camera_type).arg(camera_band
                                     ).arg(ip).arg(port).arg(user_name).arg(password).arg(item_id);
        if(!(dh->execInsert(insert_str)))
        {
            qDebug()<<"节点绑定信息数据保存失败！！";
            return false;
        }
    }
    return true;
}

bool CustomTreeModel::saveRemoveResult(QStandardItem *item)
{
    qDebug()<<item->whatsThis();
    if(item->whatsThis() == "camera"){
        Camera* camera = item->data().value<Camera*>();
        QString item_id = camera->getItemID();
        qDebug()<<item_id;
        QString delete_camera = QString("delete from camera_tree where id = '%1'").arg(item_id);
        qDebug()<<delete_camera;
        if( dh->execDelete(delete_camera)){
            return true;
        }
    }
    else{
        QString area_id = item->data().toString();
        QString delete_item = QString("delete from camera_tree where id = '%1'").arg(area_id);
        if( dh->execDelete(delete_item)){

            return true;
        }
    }
    return false;
}

bool CustomTreeModel::isInDataBase(QString item_name)
{
    bool isSelect;
    QString execStr = QString("select count(1) from camera where name = '%1'").arg(item_name);
    qDebug()<<execStr;
    QSqlQuery query = dh->execSelect(execStr,isSelect);
    query.next();
    int data_nums = query.value(0).toInt();
    qDebug()<<data_nums;
    if(isSelect && data_nums==0) return false;
    return true;
}

//void getCurrentNodeAttr


