/********************************************************************************
** Form generated from reading UI file 'videopanel.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPANEL_H
#define UI_VIDEOPANEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPanel
{
public:
    QAction *action_1;
    QAction *action_9;
    QAction *action_6;
    QAction *action_4;
    QAction *actionFullScreen;
    QAction *actionNormal;

    void setupUi(QWidget *VideoPanel)
    {
        if (VideoPanel->objectName().isEmpty())
            VideoPanel->setObjectName(QString::fromUtf8("VideoPanel"));
        VideoPanel->resize(649, 418);
        VideoPanel->setStyleSheet(QString::fromUtf8(""));
        action_1 = new QAction(VideoPanel);
        action_1->setObjectName(QString::fromUtf8("action_1"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/options.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_1->setIcon(icon);
        action_9 = new QAction(VideoPanel);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        action_9->setIcon(icon);
        action_6 = new QAction(VideoPanel);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_6->setIcon(icon);
        action_4 = new QAction(VideoPanel);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_4->setIcon(icon);
        actionFullScreen = new QAction(VideoPanel);
        actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFullScreen->setIcon(icon1);
        actionNormal = new QAction(VideoPanel);
        actionNormal->setObjectName(QString::fromUtf8("actionNormal"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/normalscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNormal->setIcon(icon2);

        retranslateUi(VideoPanel);

        QMetaObject::connectSlotsByName(VideoPanel);
    } // setupUi

    void retranslateUi(QWidget *VideoPanel)
    {
        VideoPanel->setWindowTitle(QCoreApplication::translate("VideoPanel", "Form", nullptr));
        action_1->setText(QCoreApplication::translate("VideoPanel", "\347\225\214\351\235\242\347\261\273\345\236\2131", nullptr));
        action_9->setText(QCoreApplication::translate("VideoPanel", "\347\225\214\351\235\242\347\261\273\345\236\2139", nullptr));
        action_6->setText(QCoreApplication::translate("VideoPanel", "\347\225\214\351\235\242\347\261\273\345\236\2136", nullptr));
        action_4->setText(QCoreApplication::translate("VideoPanel", "\347\225\214\351\235\242\347\261\273\345\236\2134", nullptr));
        actionFullScreen->setText(QCoreApplication::translate("VideoPanel", "\345\205\250\345\261\217", nullptr));
        actionNormal->setText(QCoreApplication::translate("VideoPanel", "\346\201\242\345\244\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoPanel: public Ui_VideoPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPANEL_H
