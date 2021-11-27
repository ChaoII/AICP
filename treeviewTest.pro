QT       += core gui xml multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0




SOURCES += \
    camera.cpp \
    cameradetaildialog.cpp \
    camerashowthread.cpp \
    customtreemodel.cpp \
    dbhelper.cpp \
    imagehelper.cpp \
    main.cpp \
    previewframe.cpp \
    servertreemodel.cpp \
    videolabel.cpp \
    videopanel.cpp \
    widget.cpp \
    windowcut.cpp

HEADERS += \
    camera.h \
    cameradetaildialog.h \
    camerashowthread.h \
    customtreemodel.h \
    dbhelper.h \
    imagehelper.h \
    previewframe.h \
    servertreemodel.h \
    utils.h \
    videolabel.h \
    videopanel.h \
    widget.h \
    windowcut.h

FORMS += \
    cameradetaildialog.ui \
    previewframe.ui \
    videopanel.ui \
    widget.ui \
    windowcut.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qrc.qrc

win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451d

INCLUDEPATH += C:/opencv/build/include


