#include "camerashowthread.h"
CameraShowThread::CameraShowThread()
{

}

CameraShowThread::CameraShowThread(Camera& cam)
{
    mCamera = cam;
    imageHelper = new ImageHelper(this);
    qDebug()<<123<<mCamera.getCameraType()<<CameraType::USBCamera;
    if (mCamera.getCameraType()==CameraType::USBCamera){
        qDebug()<<mCamera.getCameraBand().toInt();
        cap = new cv::VideoCapture(mCamera.getCameraBand().toInt());
    }
    else if(mCamera.getCameraType()==CameraType::IPCamera){
        QString IP = mCamera.getIP();
        int port = mCamera.getPort();
        QString userName = mCamera.getUserName();
        QString password = mCamera.getPassword();
        QString RtspUrl_1 = QString("rtsp://%1:%2@%3:%4/h265/ch1/main_stream").arg(userName).arg(password).arg(IP).arg(port);
        qDebug()<<RtspUrl_1;
        cap = new cv::VideoCapture(RtspUrl_1.toStdString());
    }

}

CameraShowThread::~CameraShowThread()
{

}

void CameraShowThread::run()
{
    if (cap->isOpened()){
        while(!mIsStoped){
            //            qDebug()<<QThread::currentThread();
            cap->read(img);
            if(img.empty()) continue;
            QImage qImage = imageHelper->Mat2QImg(img);
            //            QThread::msleep(30);
            //            qDebug()<<a++;
            emit imageShowFinished(qImage,mCamera.getShowLabelIndex());
        }
        QImage qImage;
        emit imageShowFinished(qImage,mCamera.getShowLabelIndex());
        cap->release();
        return;
    }
    else{
        cap->release();
        return;
    }
}

void CameraShowThread::on_stop_show_video()
{
    mIsStoped=true;
}




