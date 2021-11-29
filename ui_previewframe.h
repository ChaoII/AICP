/********************************************************************************
** Form generated from reading UI file 'previewframe.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWFRAME_H
#define UI_PREVIEWFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <videopanel.h>

QT_BEGIN_NAMESPACE

class Ui_PreviewFrame
{
public:
    QAction *actionAdd;
    QAction *actionDelete;
    QAction *actionPlay;
    QAction *actionStop;
    QAction *action_1;
    QAction *action_4;
    QAction *action_6;
    QAction *action_9;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout;
    VideoPanel *videoPanel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbOpenAll;
    QToolButton *tbCloseAll;
    QToolButton *tbFullScreen;
    QToolButton *tbCutWindow;
    QFrame *line;
    QToolButton *toolButton;

    void setupUi(QWidget *PreviewFrame)
    {
        if (PreviewFrame->objectName().isEmpty())
            PreviewFrame->setObjectName(QString::fromUtf8("PreviewFrame"));
        PreviewFrame->resize(862, 711);
        PreviewFrame->setMouseTracking(true);
        PreviewFrame->setTabletTracking(true);
        PreviewFrame->setStyleSheet(QString::fromUtf8("QToolButton:hover{\n"
"		background-color:#353637;\n"
"}\n"
"#groupBox{border-left:1px solid #1F1F1F;}\n"
"Line{\n"
"color:#1F1F1F;\n"
"}"));
        actionAdd = new QAction(PreviewFrame);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        actionDelete = new QAction(PreviewFrame);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon1);
        actionPlay = new QAction(PreviewFrame);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        actionStop = new QAction(PreviewFrame);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        action_1 = new QAction(PreviewFrame);
        action_1->setObjectName(QString::fromUtf8("action_1"));
        action_1->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/windowcut_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_1->setIcon(icon4);
        action_4 = new QAction(PreviewFrame);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_4->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/windowcut_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_4->setIcon(icon5);
        action_6 = new QAction(PreviewFrame);
        action_6->setObjectName(QString::fromUtf8("action_6"));
        action_6->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/windowcut_6.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_6->setIcon(icon6);
        action_9 = new QAction(PreviewFrame);
        action_9->setObjectName(QString::fromUtf8("action_9"));
        action_9->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/windowcut_9.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_9->setIcon(icon7);
        verticalLayout_2 = new QVBoxLayout(PreviewFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeView = new QTreeView(PreviewFrame);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        treeView->setMinimumSize(QSize(180, 0));
        treeView->setMaximumSize(QSize(230, 16777215));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setAutoFillBackground(true);
        treeView->setFrameShape(QFrame::NoFrame);
        treeView->setFrameShadow(QFrame::Plain);
        treeView->setDragEnabled(false);
        treeView->setDragDropMode(QAbstractItemView::DragOnly);
        treeView->setDefaultDropAction(Qt::LinkAction);

        horizontalLayout->addWidget(treeView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        videoPanel = new VideoPanel(PreviewFrame);
        videoPanel->setObjectName(QString::fromUtf8("videoPanel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(videoPanel->sizePolicy().hasHeightForWidth());
        videoPanel->setSizePolicy(sizePolicy1);
        videoPanel->setFocusPolicy(Qt::StrongFocus);
        videoPanel->setContextMenuPolicy(Qt::CustomContextMenu);
        videoPanel->setAcceptDrops(true);
        videoPanel->setAutoFillBackground(false);
        videoPanel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(videoPanel);

        groupBox = new QGroupBox(PreviewFrame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 30));
        groupBox->setMaximumSize(QSize(16777215, 30));
        groupBox->setFlat(false);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 5, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tbOpenAll = new QToolButton(groupBox);
        tbOpenAll->setObjectName(QString::fromUtf8("tbOpenAll"));
        tbOpenAll->setMinimumSize(QSize(20, 20));
        tbOpenAll->setMaximumSize(QSize(20, 20));
        tbOpenAll->setFocusPolicy(Qt::StrongFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/openvideos.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbOpenAll->setIcon(icon8);
        tbOpenAll->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbOpenAll);

        tbCloseAll = new QToolButton(groupBox);
        tbCloseAll->setObjectName(QString::fromUtf8("tbCloseAll"));
        tbCloseAll->setMinimumSize(QSize(20, 20));
        tbCloseAll->setMaximumSize(QSize(20, 20));
        tbCloseAll->setFocusPolicy(Qt::StrongFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/closevideos.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbCloseAll->setIcon(icon9);
        tbCloseAll->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbCloseAll);

        tbFullScreen = new QToolButton(groupBox);
        tbFullScreen->setObjectName(QString::fromUtf8("tbFullScreen"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tbFullScreen->sizePolicy().hasHeightForWidth());
        tbFullScreen->setSizePolicy(sizePolicy2);
        tbFullScreen->setMinimumSize(QSize(20, 20));
        tbFullScreen->setMaximumSize(QSize(20, 20));
        tbFullScreen->setFocusPolicy(Qt::StrongFocus);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/fullscreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbFullScreen->setIcon(icon10);
        tbFullScreen->setPopupMode(QToolButton::DelayedPopup);
        tbFullScreen->setAutoRaise(true);
        tbFullScreen->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(tbFullScreen);

        tbCutWindow = new QToolButton(groupBox);
        tbCutWindow->setObjectName(QString::fromUtf8("tbCutWindow"));
        tbCutWindow->setMinimumSize(QSize(20, 20));
        tbCutWindow->setMaximumSize(QSize(20, 20));
        tbCutWindow->setFocusPolicy(Qt::StrongFocus);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/windowcut.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbCutWindow->setIcon(icon11);
        tbCutWindow->setIconSize(QSize(20, 20));
        tbCutWindow->setCheckable(false);
        tbCutWindow->setPopupMode(QToolButton::DelayedPopup);
        tbCutWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbCutWindow->setAutoRaise(true);
        tbCutWindow->setArrowType(Qt::NoArrow);

        horizontalLayout_2->addWidget(tbCutWindow);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        horizontalLayout_2->addWidget(line);

        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(20, 20));
        toolButton->setMaximumSize(QSize(20, 20));
        toolButton->setFocusPolicy(Qt::StrongFocus);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/setting1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon12);
        toolButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(PreviewFrame);

        QMetaObject::connectSlotsByName(PreviewFrame);
    } // setupUi

    void retranslateUi(QWidget *PreviewFrame)
    {
        PreviewFrame->setWindowTitle(QCoreApplication::translate("PreviewFrame", "Form", nullptr));
        actionAdd->setText(QCoreApplication::translate("PreviewFrame", "\346\267\273\345\212\240\350\212\202\347\202\271", nullptr));
        actionDelete->setText(QCoreApplication::translate("PreviewFrame", "\345\210\240\351\231\244\350\212\202\347\202\271", nullptr));
        actionPlay->setText(QCoreApplication::translate("PreviewFrame", "\346\222\255\346\224\276", nullptr));
        actionStop->setText(QCoreApplication::translate("PreviewFrame", "\345\201\234\346\255\242", nullptr));
        action_1->setText(QCoreApplication::translate("PreviewFrame", "\347\225\214\351\235\2421", nullptr));
        action_4->setText(QCoreApplication::translate("PreviewFrame", "\347\225\214\351\235\2424", nullptr));
        action_6->setText(QCoreApplication::translate("PreviewFrame", "\347\225\214\351\235\2426", nullptr));
        action_9->setText(QCoreApplication::translate("PreviewFrame", "\347\225\214\351\235\2429", nullptr));
        groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        tbOpenAll->setToolTip(QCoreApplication::translate("PreviewFrame", "\346\211\223\345\274\200\346\211\200\346\234\211", nullptr));
#endif // QT_CONFIG(tooltip)
        tbOpenAll->setText(QCoreApplication::translate("PreviewFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        tbCloseAll->setToolTip(QCoreApplication::translate("PreviewFrame", "\345\205\263\351\227\255\346\211\200\346\234\211", nullptr));
#endif // QT_CONFIG(tooltip)
        tbCloseAll->setText(QCoreApplication::translate("PreviewFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        tbFullScreen->setToolTip(QCoreApplication::translate("PreviewFrame", "\345\205\250\345\261\217", nullptr));
#endif // QT_CONFIG(tooltip)
        tbFullScreen->setText(QCoreApplication::translate("PreviewFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        tbCutWindow->setToolTip(QCoreApplication::translate("PreviewFrame", "\346\230\276\347\244\272\347\252\227\344\275\223\345\210\206\345\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        tbCutWindow->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        tbCutWindow->setText(QCoreApplication::translate("PreviewFrame", "...", nullptr));
        toolButton->setText(QCoreApplication::translate("PreviewFrame", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewFrame: public Ui_PreviewFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWFRAME_H
