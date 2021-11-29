/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <previewframe.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *gbTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbMinium;
    QToolButton *tbMaxium;
    QToolButton *tbClose;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbPreview;
    QToolButton *tbSetting;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabMain;
    PreviewFrame *tabPreview;
    QWidget *tabSetting;
    QGroupBox *gbStatusBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(865, 535);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("#Widget{\n"
"	color:#B4B4B4;\n"
"	background:#303030;\n"
"	border-radius:20px;\n"
"}\n"
"#treeView{\n"
"	color:#B4B4B4;\n"
"	background:#303030;\n"
"}\n"
"#videoPanel{\n"
"	color:#B4B4B4;\n"
"	border:1px solid #1F1F1F;\n"
"	background:#303030;\n"
"}\n"
"QGroupBox{border:0px solid #AAAAAA;\n"
"			background-color:#262728;}\n"
"\n"
"#gbTitle,#gbStatusBar{background-color:#1F1F1F;}\n"
"\n"
"\n"
"#tbClose:hover,#tbMaxium:hover,#tbMinium:hover{\n"
"	background-color:#353637;\n"
"}\n"
"QMessageBox{\n"
"	font-size:15px;\n"
"	color:#B4B4B4;\n"
"	background-color:#303030;\n"
"	border-radius:5px\357\274\233\n"
"}\n"
"QMessageBox>QPushButton{\n"
"	color:#B4B4B4;\n"
"	background:#303030;\n"
"	border-radius:5px\357\274\233\n"
"}\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gbTitle = new QGroupBox(Widget);
        gbTitle->setObjectName(QString::fromUtf8("gbTitle"));
        gbTitle->setMinimumSize(QSize(25, 25));
        gbTitle->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_2 = new QHBoxLayout(gbTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 10, 0);
        label = new QLabel(gbTitle);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(85, 22));
        label->setMaximumSize(QSize(30, 22));
        label->setTextFormat(Qt::RichText);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo1.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tbMinium = new QToolButton(gbTitle);
        tbMinium->setObjectName(QString::fromUtf8("tbMinium"));
        tbMinium->setMinimumSize(QSize(15, 15));
        tbMinium->setMaximumSize(QSize(15, 15));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/minium.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbMinium->setIcon(icon1);
        tbMinium->setIconSize(QSize(15, 15));
        tbMinium->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbMinium);

        tbMaxium = new QToolButton(gbTitle);
        tbMaxium->setObjectName(QString::fromUtf8("tbMaxium"));
        tbMaxium->setMinimumSize(QSize(15, 15));
        tbMaxium->setMaximumSize(QSize(15, 15));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/maxium.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbMaxium->setIcon(icon2);
        tbMaxium->setIconSize(QSize(15, 15));
        tbMaxium->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbMaxium);

        tbClose = new QToolButton(gbTitle);
        tbClose->setObjectName(QString::fromUtf8("tbClose"));
        tbClose->setMinimumSize(QSize(15, 15));
        tbClose->setMaximumSize(QSize(15, 15));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbClose->setIcon(icon3);
        tbClose->setIconSize(QSize(15, 15));
        tbClose->setPopupMode(QToolButton::DelayedPopup);
        tbClose->setAutoRaise(true);

        horizontalLayout_2->addWidget(tbClose);


        verticalLayout->addWidget(gbTitle);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 25));
        groupBox->setMaximumSize(QSize(16777215, 25));
        groupBox->setStyleSheet(QString::fromUtf8("border-bottom:0px;"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 0, 0, 0);
        tbPreview = new QToolButton(groupBox);
        tbPreview->setObjectName(QString::fromUtf8("tbPreview"));
        tbPreview->setMinimumSize(QSize(25, 25));
        tbPreview->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbPreview->setIcon(icon4);
        tbPreview->setIconSize(QSize(22, 22));
        tbPreview->setCheckable(true);
        tbPreview->setChecked(true);
        tbPreview->setPopupMode(QToolButton::DelayedPopup);
        tbPreview->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbPreview->setAutoRaise(true);
        tbPreview->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(tbPreview);

        tbSetting = new QToolButton(groupBox);
        tbSetting->setObjectName(QString::fromUtf8("tbSetting"));
        tbSetting->setMinimumSize(QSize(25, 25));
        tbSetting->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbSetting->setIcon(icon5);
        tbSetting->setIconSize(QSize(22, 22));
        tbSetting->setCheckable(true);
        tbSetting->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tbSetting->setAutoRaise(true);

        horizontalLayout->addWidget(tbSetting);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox);

        tabMain = new QTabWidget(Widget);
        tabMain->setObjectName(QString::fromUtf8("tabMain"));
        tabMain->setEnabled(true);
        tabMain->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"max-height:0px;\n"
"background-color:#303030;\n"
"}\n"
"QTabWidget::pane{\n"
"\n"
"background-color:#303030;\n"
"border:0px;\n"
"}\n"
"QTabWidget::pane{\n"
"border-top:0px;\n"
"}"));
        tabMain->setDocumentMode(false);
        tabMain->setTabBarAutoHide(false);
        tabPreview = new PreviewFrame();
        tabPreview->setObjectName(QString::fromUtf8("tabPreview"));
        tabMain->addTab(tabPreview, QString());
        tabSetting = new QWidget();
        tabSetting->setObjectName(QString::fromUtf8("tabSetting"));
        tabMain->addTab(tabSetting, QString());

        verticalLayout->addWidget(tabMain);


        verticalLayout_2->addLayout(verticalLayout);

        gbStatusBar = new QGroupBox(Widget);
        gbStatusBar->setObjectName(QString::fromUtf8("gbStatusBar"));
        gbStatusBar->setMinimumSize(QSize(20, 20));
        gbStatusBar->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(gbStatusBar);


        retranslateUi(Widget);

        tabMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        gbTitle->setTitle(QString());
        label->setText(QString());
#if QT_CONFIG(tooltip)
        tbMinium->setToolTip(QCoreApplication::translate("Widget", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        tbMinium->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        tbMaxium->setToolTip(QCoreApplication::translate("Widget", "\346\234\200\345\244\247\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        tbMaxium->setText(QCoreApplication::translate("Widget", "...", nullptr));
#if QT_CONFIG(tooltip)
        tbClose->setToolTip(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
        tbClose->setText(QCoreApplication::translate("Widget", "...", nullptr));
        groupBox->setTitle(QString());
        tbPreview->setText(QCoreApplication::translate("Widget", "\351\242\204\350\247\210", nullptr));
        tbSetting->setText(QCoreApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(whatsthis)
        tabMain->setWhatsThis(QCoreApplication::translate("Widget", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        tabMain->setTabText(tabMain->indexOf(tabPreview), QCoreApplication::translate("Widget", "Tab 1", nullptr));
        tabMain->setTabText(tabMain->indexOf(tabSetting), QCoreApplication::translate("Widget", "Tab 2", nullptr));
        gbStatusBar->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
