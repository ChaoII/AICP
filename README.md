# 1.ICP功能
概述：基于Qt6.2编写的C++窗体程序， ICP旨在打造一款只能摄像平台，能够接入IP摄像头（带rtsp协议，目前暂未考虑对应SDK，非工作重点），USB摄像头，工业摄像探头，并且在系统中进行显示，并且加入智能算法，比如对象检测、人脸识别、对象跟踪、语义分割、实例分割、OCR等功能。
系统环境：
- Qt6.2
- OpenCV==4.5.1
- paddleinference==2.2(暂未加入，等待接入够最新稳定版本)
- OpenVINO
- cuda11.0+cudnn8+trt7(暂定，目前电脑没显卡)

# 2.已完成工作
- 搭建基础框架，采用framless模式作为主框架
- videopanel多路显示，支持1,4,6,9摄像头
- 设备树，摄像头信息维护，右键菜单
- 设备信息存储sqllite
- 画面全屏
- IP摄像头及USB摄像头接入
- 其它样式功能等优化
# 3.系统截图
- 系统总览设备树
![image](https://user-images.githubusercontent.com/44053467/143818289-50c15974-b38a-499e-97e6-36152cc4d57d.png)
- 多路摄像头支持
![image](https://user-images.githubusercontent.com/44053467/143818309-4b0cb26e-e3c9-44f0-94cf-6ad53c2d8d9a.png)
- 系统全屏
![image](https://user-images.githubusercontent.com/44053467/143818343-a35971da-1c6c-4d8d-8851-363306afab59.png)
- 摄像头接入
![image](https://user-images.githubusercontent.com/44053467/143818514-729d2b66-af8f-4c89-bca5-04668886ffeb.png)

# 4.下一步工作计划
- 优化启动后camera对象及对应线程容器
- 处理IPCamera未连接启动摄像头系统崩溃问题
- 新增启动全部摄像头功能
- 新增关闭全部摄像头功能
- 优化videopanel切换显示问题
- 新增全局.qss文件
# 5.稍远期工作计划
- 增加人脸识别功能

# 6.长期工作计划
- 集成paddlepaddle模型，实现对象检测，对象跟踪、语义分割、实例分割、OCR
- intel Cpu 采用openvino优化
- trt加速（笔记本没nvidia显卡）
- ncnn加速（还没开始学习）

# 7.最后
本人也是菜鸡，边学边摸索
