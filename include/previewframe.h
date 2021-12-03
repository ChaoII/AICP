#ifndef PREVIEWFRAME_H
#define PREVIEWFRAME_H
#include <QWidget>
#include "camera.h"
#include "cameradetaildialog.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QImageCapture>
#include <QMap>
#include <QTimer>
#include  "camerashowthread.h"
#include "ui_previewframe.h"
#include "windowcut.h"
#include <QDrag>
#include <QMimeData>
#include "customtreemodel.h"
#include "dbhelper.h"

namespace Ui {
class PreviewFrame;
}

struct CameraStruct{
    Camera* camera;
    CameraShowThread* cameraShowThread;
};



class PreviewFrame : public QWidget
{
    Q_OBJECT
private:
    int labelIndex=0;
    QStandardItemModel * listModel;
    QItemSelectionModel * treeSelection;
    QItemSelectionModel * listSelecttion;
//    CServerTreeModel* xmlModel;
    CustomTreeModel * xmlModel;


public:
    PreviewFrame(QWidget *parent = nullptr);
    void initTreeView();
    void removeNode(QStandardItem * item);
    int getAvaliabelLabel();
    int getLabelIndex();
    void getAllCameraInfo(QStandardItem * item);

    ~PreviewFrame();

protected:
    virtual void keyPreddEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);

private slots:

    void on_treeView_customContextMenuRequested(const QPoint &pos);

    void on_actionAdd_triggered();

    void on_actionDelete_triggered();

    void on_processCapturedImage(const QImage &img,int labelIndex);

    void on_treeView_doubleClicked(const QModelIndex &index);

    void on_actionPlay_triggered();

    void on_actionStop_triggered();

    void on_tbFullScreen_clicked();

    void on_tbCutWindow_clicked();

    void on_tbOpenAll_clicked();

    void on_tbCloseAll_clicked();

private:
    Ui::PreviewFrame *ui;
    QMap<QString,CameraStruct> cameraMap;
    std::deque<int> labelListIndex{0,1,2,3,4,5,6,7,8,9};
    WindowCut *windowCut=nullptr;
    DbHelper * dh_;
};
#endif // WIDGET_H

