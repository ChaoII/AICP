#ifndef CUSTOMTREEMODEL_H
#define CUSTOMTREEMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include <QStandardItem>
#include "dbhelper.h"
#include "camera.h"
class CustomTreeModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit CustomTreeModel(QObject *parent = nullptr);

    void CreateModelFromDBFile(const QString& fileName);

    void addSubNode(const QString& parentID, QStandardItem * item);

    DbHelper *getDbHelper();

    Camera* bindCamerainfo(QSqlQuery & query);

    bool saveCameraNode(QStandardItem*  parentitem,QStandardItem*  item);

    bool saveRemoveResult(QStandardItem*  item);

    bool isInDataBase(QString item_name);


signals:

private:
    DbHelper *dh;
    QMap<int,QString> camera_type_dict;
};

#endif // CUSTOMTREEMODEL_H
