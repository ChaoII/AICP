#ifndef CAMERASHOWTHREAD_H
#define CAMERASHOWTHREAD_H

#include <QObject>
#include <QThread>
#include "camera.h"
#include "imagehelper.h"
#include <QMutex>


class CameraShowThread : public QThread
{
    Q_OBJECT
public:
    CameraShowThread();
    CameraShowThread(Camera& cam);
    ~CameraShowThread();
protected:
    void run();

signals:
    void imageShowFinished(const QImage& ,int);

public:
    void on_stop_show_video();

private:
    cv::Mat img;
    cv::VideoCapture *cap=nullptr;
    ImageHelper *imageHelper;
    Camera mCamera;
    bool mIsStoped=false;
};

#endif // CAMERASHOWTHREAD_H
