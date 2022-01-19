#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <qt_windows.h>
#include "hkhelper.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE



class Widget : public QWidget
{
    Q_OBJECT
private:

public:
    Widget(QWidget *parent = nullptr);
//    enum MousePoss{LeftUp=0,Up,RightUp,Right,RightDown,Down,LeftDown,Left,Middle};
//    MousePoss calcMousePoss(QPoint p);
//    void setCursorType(MousePoss type);
//    void changeWindowSize(MousePoss type, QRect &wid,QPoint ptemp,int minWidth, int minHeight);

    ~Widget();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);


private slots:

    void on_tbPreview_clicked();

    void on_tbSetting_clicked();

    void on_tbMinium_clicked();

    void on_tbMaxium_clicked();

    void on_tbClose_clicked();

protected:

private:
    Ui::Widget *ui;
    QPointF dragPosition;
    bool mMoveable=false;
    HKHelper * hk_helper;
//    MousePoss mCurPos;
//    QPoint last;
//    const int MOUSE_MARGIN=10;
};
#endif // WIDGET_H
