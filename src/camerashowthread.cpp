#include "camerashowthread.h"
#include <QTime>
CameraShowThread::CameraShowThread()
{
    use_sdk = false;
}

CameraShowThread::CameraShowThread(Camera* cam)
{
    use_sdk = false;
    mCamera = cam;
    imageHelper = new ImageHelper(this);
    if (mCamera->getCameraType()==CameraType::USBCamera){
        cap = new cv::VideoCapture(mCamera->getCameraBand().toInt());
    }
    else if(mCamera->getCameraType()==CameraType::IPCamera)
    {
        QString IP = mCamera->getIP();
        int port = mCamera->getPort();
        QString userName = mCamera->getUserName();
        QString password = mCamera->getPassword();
        if (use_sdk){
            hk_helper = new HKHelper(this);
            //add SDK info
            hk_helper->play_custom(IP,port,userName,password);
            connect(hk_helper,&HKHelper::decode_image_cv, [=](cv::Mat img){
                qDebug()<<"______________________________________________________";
//                QImage qImage = imageHelper->Mat2QImg(img);
//                emit imageShowFinished(qImage,mCamera->getShowLabelIndex());
            });
        }
        else{

            QString RtspUrl_1 = QString("rtsp://%1:%2@%3:%4/h265/ch1/main_stream").arg(userName).arg(password).arg(IP).arg(port);
            qDebug()<<"IP摄像头RTSP地址："<<RtspUrl_1;
            cap = new cv::VideoCapture(RtspUrl_1.toStdString());
            qDebug()<<"IPCamera is opened!";
        }
    }
    if(cap!=nullptr){
        cap->set(cv::CAP_PROP_FOURCC,cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
        cap->set(cv::CAP_PROP_FPS,30);
        //    cap->set(cv::CAP_PROP_FRAME_WIDTH, 1921);//宽度
        //    cap->set(cv::CAP_PROP_FRAME_HEIGHT, 1080);//高度
        qDebug()<<cap->get(cv::CAP_PROP_FRAME_WIDTH);
        qDebug()<<cap->get(cv::CAP_PROP_FRAME_HEIGHT);
    }
}


void CameraShowThread::run()
{
    if (use_sdk)
    {
        return;
    }
    else
    {
        if (cap->isOpened())
        {
            while(!mIsStoped){
                //            qDebug()<<QThread::currentThread();
                QTime start_time = QTime::currentTime();
                cap->read(img);
                QTime end_time = QTime::currentTime();
                qDebug()<<"FPS:"<<1000.0f/(end_time.msec()-start_time.msec());
                if(img.empty()) continue;

                QImage qImage = imageHelper->Mat2QImg(img);
                emit imageShowFinished(qImage,mCamera->getShowLabelIndex());
            }
            QImage qImage;
            emit imageShowFinished(qImage,mCamera->getShowLabelIndex());
            cap->release();
            return;
        } // cap is opened
        else
        {
            cap->release();
            return;
        }
    }//not use sdk

}

void CameraShowThread::on_stop_show_video()
{
    mIsStoped=true;
}

CameraShowThread::~CameraShowThread()
{
    qDebug()<<"开始析构 CameraShowThread";
    if(!(imageHelper==nullptr)){
        delete imageHelper;
        imageHelper=nullptr;
    }
    if(!(cap == nullptr)){
        cap->release();
        cap=nullptr;
    }

    qDebug()<<"析构完成 CameraShowThread";
}




