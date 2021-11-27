#include "camera.h"

Camera::Camera()
{
    mAllCameraDevices = QMediaDevices::videoInputs();
}

Camera::~Camera()
{

}
//设置camera基本属性
void Camera::setIPCamera(QString name, QString IP, int port, QString userName,
                         QString password, QString cameraType, QString cameraBand,QString item_id)
{
    mName=name;
    mIP=IP;
    mPort=port;
    mUserName=userName;
    mPassword=password;
    setCameraType(cameraType);
    setCameraBand(cameraBand);
    mItemId=item_id;
}

//get camera 属性
QString Camera::getName(){return mName;}
QString Camera::getIP(){return mIP;}
int Camera::getPort(){return mPort;}
QString Camera::getUserName(){return mUserName;}
QString Camera::getPassword(){return mPassword;}
CameraType Camera::getCameraType(){return mCameraType;}
CameraBand Camera::getCameraBand(){return mCameraBand;}

void Camera::setCameraType(QString cameraType)
{
    if (cameraType=="USBCamera")
        mCameraType= CameraType::USBCamera;
    else if(cameraType=="IPCamera")
        mCameraType= CameraType::IPCamera;
    else
        mCameraType=CameraType::OtherType;
}

void Camera::setCameraBand(QString cameraBand)
{
    if (cameraBand=="HK")
        mCameraBand= CameraBand::HK;
    else if(cameraBand=="DH")
        mCameraBand= CameraBand::DH;
    else
        mCameraBand=CameraBand::OtherBand;
}

// 读取所有USB或类USB摄像头(CSI)
QList<QCameraDevice> Camera::getReadyUSBCamera()
{
    return mAllCameraDevices;
}
// 获取当前摄像头index
void Camera::setCurrentCameraIndex(int index)
{
    mCurrentCameraIndex= index;
}

int Camera::getCurrentCameraIndex()
{
    return mCurrentCameraIndex;
}

bool Camera::getStartStatus()
{
    return mIsStarted;
}

void Camera::setStartStatus(bool startStstus)
{
    mIsStarted = startStstus;

}
QString Camera::getItemID(){

    return mItemId;
}

bool Camera::getConnectStatus()
{
    //开启线程或者定时器检测IP摄像头的可用状态
    return false;
}

void Camera::setShowLabelindex(int cameraShowLabel)
{
    mCameraShowLabelIndex=cameraShowLabel;
}

int Camera::getShowLabelIndex()
{
    return mCameraShowLabelIndex;
}


