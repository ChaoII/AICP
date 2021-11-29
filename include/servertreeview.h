#ifndef SERVERTREEVIEW_H
#define SERVERTREEVIEW_H
#include "servertreemodel.h"
#include <QWidget>

class CServerTreeView
{
public:
    CServerTreeView(QObject *parent);
    ~CServerTreeView();
    void initTreeView();
    void receiveByte(QByteArray byteArray);
private:
    CServerTreeModel* p_model;
};

#endif // SERVERTREEVIEW_H
