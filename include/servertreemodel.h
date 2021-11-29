#ifndef SERVERTREEMODEL_H
#define SERVERTREEMODEL_H
#include <QStandardItemModel>
#include <QDomDocument>


class CServerTreeModel:public QStandardItemModel
{
public:
    CServerTreeModel(QObject *parent);
    ~CServerTreeModel();
    bool readFile(const QString &fileName);
    void parseAllMembers(const QDomElement &element,QStandardItem *ParentItem);
};

#endif // SERVERTREEMODEL_H
