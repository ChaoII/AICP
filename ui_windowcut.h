/********************************************************************************
** Form generated from reading UI file 'windowcut.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWCUT_H
#define UI_WINDOWCUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowCut
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;

    void setupUi(QWidget *WindowCut)
    {
        if (WindowCut->objectName().isEmpty())
            WindowCut->setObjectName(QString::fromUtf8("WindowCut"));
        WindowCut->resize(197, 56);
        WindowCut->setStyleSheet(QString::fromUtf8("#WindowCut{\n"
"	color:#B4B4B4;\n"
"	background:#262728;\n"
"	border-radius:15px;\n"
"	border:0px;\n"
"}"));
        horizontalLayout = new QHBoxLayout(WindowCut);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(8, 8, 8, 8);
        toolButton = new QToolButton(WindowCut);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setMinimumSize(QSize(40, 40));
        toolButton->setMaximumSize(QSize(40, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/windowcut_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(38, 38));
        toolButton->setCheckable(true);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(WindowCut);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(40, 40));
        toolButton_2->setMaximumSize(QSize(40, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/windowcut_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(38, 38));
        toolButton_2->setCheckable(true);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(WindowCut);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(40, 40));
        toolButton_3->setMaximumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/windowcut_6.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(38, 38));
        toolButton_3->setCheckable(true);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(WindowCut);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(40, 40));
        toolButton_4->setMaximumSize(QSize(40, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/windowcut_9.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(38, 38));
        toolButton_4->setCheckable(true);
        toolButton_4->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_4);


        retranslateUi(WindowCut);

        QMetaObject::connectSlotsByName(WindowCut);
    } // setupUi

    void retranslateUi(QWidget *WindowCut)
    {
        WindowCut->setWindowTitle(QCoreApplication::translate("WindowCut", "Form", nullptr));
        toolButton->setText(QCoreApplication::translate("WindowCut", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("WindowCut", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("WindowCut", "...", nullptr));
        toolButton_4->setText(QCoreApplication::translate("WindowCut", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowCut: public Ui_WindowCut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWCUT_H
