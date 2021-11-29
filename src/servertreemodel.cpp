#include "servertreemodel.h"
#include <QFile>
#include "camera.h"
#include <iostream>
#include <QFileInfo>

CServerTreeModel::CServerTreeModel(QObject *parent) : QStandardItemModel(parent)
{

}
CServerTreeModel::~CServerTreeModel()
{

}

///
/// \brief CServerTreeModel::readFile
/// \param fileName: xml文件名
/// \return 是否正确读取xml文件返回true or false
///
bool CServerTreeModel::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        std::cerr << "Error: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr) << std::endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    QStandardItem* item1;
    if (root.tagName() != "root")
    {
        std::cerr << "Error: Not a school file" << std::endl;
        return false;
    }
    else{
        QString value = "监控信息";
        item1= new QStandardItem((value));
        this->appendRow(item1);
    }
    parseAllMembers(root,item1);
    return true;
}
///
/// \brief CServerTreeModel::parseAllMembers
/// \param element QDomElement 文档元素
/// \param ParentItem QStandardItem 项
///
void CServerTreeModel::parseAllMembers(const QDomElement &element,QStandardItem *ParentItem)
{
    //获取主节点下的第一个节点（node）
    QDomNode child = element.firstChild();
    QList<QStandardItem*> childItems;
    QStandardItem* ChildItem;
    while(!child.isNull())
    {
        QDomElement childElement = child.toElement();
        if(child.nodeName()=="camera"){
            QIcon ico(":/images/IPCamera.png");
            if (childElement.attribute("type")=="USBCamera"){
                ico = QIcon(":/images/USBCamera.png");
            }
            //节点name属性
            QString readvalue = childElement.attribute("name");
            ChildItem= new QStandardItem(ico,readvalue);
            //设置item ID
            ChildItem->setWhatsThis("camera");
            //获取摄像头对象属性包括类型、品牌、IP、Port、用户名、密码
            QString cameraType = childElement.attribute("type");
            QString cameraBand =childElement.attribute("band");
            QString IP = child.toElement().attribute("IP");
            int port = child.toElement().attribute("port").toInt();
            QString userName = child.toElement().attribute("userName");
            QString password = child.toElement().attribute("password");
            Camera* camera = new Camera;;
            camera->setIPCamera(readvalue, IP,  port,  userName,  password,  cameraType,  cameraBand,"");
            //camera属性绑定至item
            ChildItem->setData(QVariant::fromValue(camera));
        }
        else if(child.nodeName()=="area"){
            ChildItem = new QStandardItem(QIcon(":/images/area.png"),childElement.attribute("name"));
            ChildItem->setWhatsThis("area");
        }
        childItems.clear();
        childItems.push_back(ChildItem);
        ParentItem->appendRows(childItems);
        childItems.clear();
        if (child.nodeName() =="area")
        {
            //递归调用解析方法，直至xml节点解析完毕
            parseAllMembers(child.toElement(),ChildItem);
        }
        child = child.nextSibling();
    }
}
