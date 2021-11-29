/********************************************************************************
** Form generated from reading UI file 'cameradetaildialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADETAILDIALOG_H
#define UI_CAMERADETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CameraDetailDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *editUserName;
    QLineEdit *editPassword;
    QComboBox *cmbBand;
    QLabel *label_2;
    QComboBox *cmbType;
    QLineEdit *editName;
    QLineEdit *editIP;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *editPort;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CameraDetailDialog)
    {
        if (CameraDetailDialog->objectName().isEmpty())
            CameraDetailDialog->setObjectName(QString::fromUtf8("CameraDetailDialog"));
        CameraDetailDialog->resize(466, 167);
        verticalLayout = new QVBoxLayout(CameraDetailDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        editUserName = new QLineEdit(CameraDetailDialog);
        editUserName->setObjectName(QString::fromUtf8("editUserName"));

        gridLayout->addWidget(editUserName, 2, 3, 1, 1);

        editPassword = new QLineEdit(CameraDetailDialog);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editPassword, 3, 1, 1, 1);

        cmbBand = new QComboBox(CameraDetailDialog);
        cmbBand->addItem(QString());
        cmbBand->addItem(QString());
        cmbBand->setObjectName(QString::fromUtf8("cmbBand"));

        gridLayout->addWidget(cmbBand, 0, 3, 1, 1);

        label_2 = new QLabel(CameraDetailDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        cmbType = new QComboBox(CameraDetailDialog);
        cmbType->addItem(QString());
        cmbType->addItem(QString());
        cmbType->setObjectName(QString::fromUtf8("cmbType"));

        gridLayout->addWidget(cmbType, 0, 1, 1, 1);

        editName = new QLineEdit(CameraDetailDialog);
        editName->setObjectName(QString::fromUtf8("editName"));

        gridLayout->addWidget(editName, 1, 1, 1, 1);

        editIP = new QLineEdit(CameraDetailDialog);
        editIP->setObjectName(QString::fromUtf8("editIP"));

        gridLayout->addWidget(editIP, 1, 3, 1, 1);

        label = new QLabel(CameraDetailDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_6 = new QLabel(CameraDetailDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_7 = new QLabel(CameraDetailDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        editPort = new QLineEdit(CameraDetailDialog);
        editPort->setObjectName(QString::fromUtf8("editPort"));

        gridLayout->addWidget(editPort, 2, 1, 1, 1);

        label_5 = new QLabel(CameraDetailDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_3 = new QLabel(CameraDetailDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(CameraDetailDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(CameraDetailDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CameraDetailDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CameraDetailDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CameraDetailDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CameraDetailDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraDetailDialog)
    {
        CameraDetailDialog->setWindowTitle(QCoreApplication::translate("CameraDetailDialog", "Dialog", nullptr));
        cmbBand->setItemText(0, QCoreApplication::translate("CameraDetailDialog", "HK", nullptr));
        cmbBand->setItemText(1, QCoreApplication::translate("CameraDetailDialog", "DH", nullptr));

        label_2->setText(QCoreApplication::translate("CameraDetailDialog", "\347\253\257\345\217\243:", nullptr));
        cmbType->setItemText(0, QCoreApplication::translate("CameraDetailDialog", "IPCamera", nullptr));
        cmbType->setItemText(1, QCoreApplication::translate("CameraDetailDialog", "USBCamera", nullptr));

        editIP->setInputMask(QCoreApplication::translate("CameraDetailDialog", "000.000.000.000", nullptr));
        label->setText(QCoreApplication::translate("CameraDetailDialog", "\345\220\215\347\247\260\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("CameraDetailDialog", "\347\261\273\345\236\213\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("CameraDetailDialog", "\345\223\201\347\211\214\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("CameraDetailDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("CameraDetailDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("CameraDetailDialog", "IP:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraDetailDialog: public Ui_CameraDetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADETAILDIALOG_H
