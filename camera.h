#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <QObject>
#include <QCamera>
#include <QLabel>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QUuid>

enum CameraType{
    IPCamera=0,
    USBCamera,
    OtherType,
};
enum CameraBand{
    HK,
    DH,
    OtherBand,
};
class Camera
{
public:
public:
    Camera();
    ~Camera();
    void setIPCamera(QString name,QString IP,int port,QString userName,QString password,QString cameraType,QString cameraBand,QString item_id);
    QString getName();
    QString getIP();
    int getPort();
    QString getUserName();
    QString getPassword();
    CameraType getCameraType();
    CameraBand getCameraBand();
    void setCameraType(QString type);
    void setCameraBand(QString band);
    QString getItemID();
    QList<QCameraDevice> getReadyUSBCamera();
    void setCurrentCameraIndex(int index);
    int getCurrentCameraIndex();
    bool getStartStatus();
    void setStartStatus(bool startStstus);
    bool getConnectStatus();
    void setShowLabelindex(int showLabelIndex);
    int getShowLabelIndex();




private:
    QString mName;
    QString mIP;
    int mPort;
    QString mUserName;
    QString mPassword;
    QString mItemId;
    CameraType mCameraType;
    CameraBand mCameraBand;
    int mCurrentCameraIndex;
    QList<QCameraDevice> mAllCameraDevices;
    bool mIsStarted= false;
    bool mConnectStatus = false;
    int mCameraShowLabelIndex;
};

#endif // CAMERA_H
