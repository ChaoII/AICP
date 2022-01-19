#ifndef HKHELPER_H
#define HKHELPER_H

#include <QObject>
#include <QDebug>
#include "HCNetSDK.h"
#include "plaympeg4.h"
#include <opencv2/opencv.hpp>

class HKHelper:public QObject
{
    Q_OBJECT
public:

    explicit HKHelper(QObject *parent = nullptr);

    void real_play_by_win(QString ip,int port,QString user_name ,QString password,HWND win_id);
    void stop_play(LONG lRealPlayHandle);
    void device_logout(LONG lUserID);
    void play_custom(QString ip,int port,QString user_name ,QString password);




private:
    void uninit_SDK();
    LONG device_login(QString ip,int port,QString user_name ,QString password);
    void show_custom(LONG lUserID);


private:
    bool is_inited;

public:
    static HKHelper * s_this;
    static LONG g_nPort;
    static cv::Mat g_BGRImage;
    static void CALLBACK DecCBFun(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, long nUser, long nReserved2);
signals:
    void decode_image_cv(cv::Mat img);


};

#endif // HKHELPER_H
