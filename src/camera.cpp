#include "camera.h"

Camera::Camera()
{
    camera_nums++;
    mAllCameraDevices = QMediaDevices::videoInputs();
    qDebug()<<"创建了camera"<<QString::number(camera_nums);
}

Camera::~Camera()
{

    qDebug()<<"析构了camera"<<QString::number(camera_nums);
    camera_nums--;
}

///
/// \brief Camera::setIPCamera 设置camera基本属性
/// \param name 摄像头名称，不能重复
/// \param IP 摄像头IP,USB摄像头则为空
/// \param port 端口号USB摄像头端口号默认为0
/// \param userName IP摄像头RTSP地址用户名
/// \param password IP摄像头RTSP地址密码
/// \param cameraType 摄像头类型，USB摄像头，IP摄像头
/// \param cameraBand 摄像头品牌，海康，大华
/// \param item_id 节点id
///
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
int Camera::camera_nums = 0;
//get camera 属性
QString Camera::getName(){return mName;}
QString Camera::getIP(){return mIP;}
int Camera::getPort(){return mPort;}
QString Camera::getUserName(){return mUserName;}
QString Camera::getPassword(){return mPassword;}
CameraType Camera::getCameraType(){return mCameraType;}
QString Camera::getCameraBand(){return mCameraBand;}

///
/// \brief Camera::setCameraType
/// \param cameraType
///
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
     mCameraBand=cameraBand;
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


