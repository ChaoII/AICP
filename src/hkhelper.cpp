#include "hkhelper.h"

void CALLBACK g_ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
    char tempbuf[256] = {0};
    Q_UNUSED(tempbuf);
    switch(dwType)
    {
    case EXCEPTION_RECONNECT:    //预览时重连
        qDebug()<<QString("----------reconnect--------%1\n").arg(time(NULL));
        break;
    default:
        break;
    }
}
HKHelper* HKHelper::s_this = nullptr;
HKHelper::HKHelper(QObject *parent):QObject(parent)
{
    //初始化海康SDK
    is_inited = NET_DVR_Init();
    qDebug() << "SDK init ok";
    //设置连接时间与重连时间
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);
    //设置异常消息回调函数
    NET_DVR_SetExceptionCallBack_V30(0, NULL,g_ExceptionCallBack, NULL);
    s_this = this;
}





void HKHelper::real_play_by_win(QString ip, int port, QString user_name, QString password,HWND win_id)
{

    LONG lUserID = device_login( ip,  port,  user_name,  password);

    if (lUserID < 0)
    {
        qDebug()<<QString("Login failed, error code:{0}\n").arg(NET_DVR_GetLastError());
        NET_DVR_Cleanup();
        return;
    }

    //---------------------------------------
    //启动预览并设置回调数据流
    LONG lRealPlayHandle;
    NET_DVR_PREVIEWINFO struPlayInfo = {0};
    struPlayInfo.hPlayWnd = win_id;       //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel     = 1;       //预览通道号
    struPlayInfo.dwStreamType = 0;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode   = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked     = 1;       //0- 非阻塞取流，1- 阻塞取流

    //直接解码，无需自定义解码
    lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, NULL, NULL);
    if (lRealPlayHandle < 0)
    {
        qDebug()<<"NET_DVR_RealPlay_V40 error\n";
        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return;
    }
    //---------------------------------------
    return;
}

LONG HKHelper::device_login(QString ip, int port, QString user_name, QString password)
{
    //登录参数，包括设备地址、登录用户、密码等
    NET_DVR_USER_LOGIN_INFO struLoginInfo;
    struLoginInfo.bUseAsynLogin = 0; //同步登录方式
    strcpy_s(struLoginInfo.sDeviceAddress, ip.toLatin1().data()); //设备IP地址
    struLoginInfo.wPort = port; //设备服务端口
    strcpy_s(struLoginInfo.sUserName, user_name.toLatin1().data()); //设备登录用户名
    strcpy_s(struLoginInfo.sPassword, password.toLatin1().data()); //设备登录密码

    //设备信息, 输出参数
    NET_DVR_DEVICEINFO_V40 struDeviceInfoV40;

    LONG lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
    return lUserID;
}

void HKHelper::stop_play(LONG lRealPlayHandle)
{
    //关闭预览
    NET_DVR_StopRealPlay(lRealPlayHandle);
}

void HKHelper::uninit_SDK()
{
    //释放SDK资源
    NET_DVR_Cleanup();
}

void HKHelper::device_logout(LONG lUserID)
{
    //注销用户
    NET_DVR_Logout(lUserID);
}


LONG HKHelper::g_nPort=-100;
void HKHelper::DecCBFun(long nPort, char* pBuf, long nSize, FRAME_INFO* pFrameInfo, long nUser, long nReserved2)
{
    if (pFrameInfo->nType == T_YV12)
    {
        qDebug() << "the frame infomation is T_YV12";
        cv::Mat g_BGRImage;
        if (g_BGRImage.empty())
        {
            g_BGRImage.create(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC3);
        }
        cv::Mat YUVImage(pFrameInfo->nHeight + pFrameInfo->nHeight / 2, pFrameInfo->nWidth, CV_8UC1, (unsigned char*)pBuf);

        cvtColor(YUVImage, g_BGRImage, cv::COLOR_YUV2BGR_YV12);
        cv::resize(g_BGRImage,g_BGRImage,cv::Size(0,0),0.5,0.5);
        emit s_this->decode_image_cv(g_BGRImage);
        qDebug()<<"__________________________________";
    }
}

//实时视频码流数据获取 回调函数
void CALLBACK g_RealDataCallBack_V30(LONG lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void* pUser)
{
    if (dwDataType == NET_DVR_STREAMDATA)//码流数据
    {
        if (dwBufSize > 0 && HKHelper::g_nPort != -1)
        {
            if (!PlayM4_InputData(HKHelper::g_nPort, pBuffer, dwBufSize))
            {
                std::cout << "fail input data" << std::endl;
            }
            else
            {
                std::cout << "success input data" << std::endl;
            }

        }
    }
}

void HKHelper::play_custom(QString ip,int port,QString user_name ,QString password)
{

    //数据解码回调函数，
    //功能：将YV_12格式的视频数据流转码为可供opencv处理的BGR类型的图片数据，并实时显示

    //登录函数，用作摄像头id以及密码输入登录
    LONG lUserID = device_login(ip, port, user_name, password);
    //bool HK_camera::Login(const char* sDeviceAddress,const char* sUserName,const char* sPassword, WORD wPort);        //登陆（VS2017版本）


    if (lUserID>=0)//用户名以及密码，根据此系列博客一中的方法查看或设置
    {
        qDebug() << "login successfully";
        this->show_custom(lUserID);
    }
    else
    {
        qDebug() << "login fail";
    }

}

void HKHelper::show_custom(LONG lUserID)
{

    if (PlayM4_GetPort(&g_nPort))            //获取播放库通道号
    {
        if (PlayM4_SetStreamOpenMode(g_nPort, STREAME_REALTIME))      //设置流模式
        {
            if (PlayM4_OpenStream(g_nPort, NULL, 0, 1024 * 1024))         //打开流
            {
                if (PlayM4_SetDecCallBackExMend(g_nPort,DecCBFun, NULL, 0, NULL))
                {
                    if (PlayM4_Play(g_nPort, NULL))
                    {
                        std::cout << "success to set play mode" << std::endl;
                    }
                    else
                    {
                        std::cout << "fail to set play mode" << std::endl;
                    }
                }
                else
                {
                    std::cout << "fail to set dec callback " << std::endl;
                }
            }
            else
            {
                std::cout << "fail to open stream" << std::endl;
            }
        }
        else
        {
            std::cout << "fail to set stream open mode" << std::endl;
        }
    }
    else
    {
        std::cout << "fail to get port" << std::endl;
    }
    //启动预览并设置回调数据流
    NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
    struPlayInfo.hPlayWnd = NULL; //窗口为空，设备SDK不解码只取流
    struPlayInfo.lChannel = 1; //Channel number 设备通道
    struPlayInfo.dwStreamType = 0;// 码流类型，0-主码流，1-子码流，2-码流3，3-码流4, 4-码流5,5-码流6,7-码流7,8-码流8,9-码流9,10-码流10
    struPlayInfo.dwLinkMode = 0;// 0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-RTP/RTSP,5-RSTP/HTTP
    struPlayInfo.bBlocked = 1; //0-非阻塞取流, 1-阻塞取流, 如果阻塞SDK内部connect失败将会有5s的超时才能够返回,不适合于轮询取流操作.

    if (NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, g_RealDataCallBack_V30, NULL))
    {
        //        cv::namedWindow("RGBImage2");
    }
}

