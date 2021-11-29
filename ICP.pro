QT       += core gui xml multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0




SOURCES += \
    src/camera.cpp \
    src/cameradetaildialog.cpp \
    src/camerashowthread.cpp \
    src/customtreemodel.cpp \
    src/dbhelper.cpp \
    src/imagehelper.cpp \
    src/main.cpp \
    src/previewframe.cpp \
    src/servertreemodel.cpp \
    src/videolabel.cpp \
    src/videopanel.cpp \
    src/widget.cpp \
    src/windowcut.cpp

HEADERS += \
    include/camera.h \
    include/cameradetaildialog.h \
    include/camerashowthread.h \
    include/customtreemodel.h \
    include/dbhelper.h \
    include/imagehelper.h \
    include/previewframe.h \
    include/servertreemodel.h \
    include/utils.h \
    include/videolabel.h \
    include/videopanel.h \
    include/widget.h \
    include/windowcut.h

FORMS += \
    ui/cameradetaildialog.ui \
    ui/previewframe.ui \
    ui/videopanel.ui \
    ui/widget.ui \
    ui/windowcut.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/qrc.qrc

win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world451d

INCLUDEPATH += C:/opencv/build/include
INCLUDEPATH += ./include

