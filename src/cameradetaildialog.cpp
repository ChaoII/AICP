#include "cameradetaildialog.h"
#include "ui_cameradetaildialog.h"

CameraDetailDialog::CameraDetailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraDetailDialog)
{
    ui->setupUi(this);
    QStringList qss;
    qss.append("QDialog{color:#F0F0F0;border:1px solid #AAAAAA;background:#303030;}");
    qss.append("QLineEdit,QComboBox{color:#F0F0F0;background:#555555;}");
    qss.append("QLabel{color:#F0F0F0;}");
    this->setStyleSheet(qss.join(""));
    mCam = new Camera;
    setAttribute(Qt::WA_DeleteOnClose);
}

CameraDetailDialog::~CameraDetailDialog()
{
    delete ui;
    if (!isCorrectSend) delete mCam;
}

void CameraDetailDialog::on_buttonBox_accepted()
{
    QString name=ui->editName->text();
    QString IP=ui->editIP->text();
    int port=ui->editPort->text().toInt();
    QString userName=ui->editUserName->text();
    QString password=ui->editPassword->text();
    QString cameraType=ui->cmbType->currentText();
    QString cameraBand=ui->cmbBand->currentText();
    QString item_id = QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
    mCam->setIPCamera(name,IP,port,userName,password,cameraType,cameraBand,item_id);
    if(mCam->getCameraType()==CameraType::USBCamera){
        qDebug()<<"进了cameratype";
        QString cameraBand=QString::number( ui->cmbBand->currentIndex());
        mCam->setCameraBand(cameraBand);
    }
    emit sendCameraDetail(mCam);
    isCorrectSend = true;
}


void CameraDetailDialog::on_cmbType_currentTextChanged(const QString &arg1)
{
    if (arg1=="USBCamera"){
        ui->cmbBand->clear();
        for(auto &camera:mCam->getReadyUSBCamera()){
            ui->cmbBand->addItem(camera.description());
        }
        ui->editIP->setEnabled(false);
        ui->editName->setEnabled(false);
        ui->editPassword->setEnabled(false);
        ui->editPort->setEnabled(false);
        ui->editUserName->setEnabled(false);
    }
    else {
        ui->editIP->setEnabled(true);
        ui->editName->setEnabled(true);
        ui->editPassword->setEnabled(true);
        ui->editPort->setEnabled(true);
        ui->editUserName->setEnabled(true);
    }
}


void CameraDetailDialog::on_cmbBand_currentTextChanged(const QString &arg1)
{
    if(ui->cmbType->currentText()=="USBCamera"){
        ui->editName->setText(arg1);
        ui->label_2->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
        ui->label_3->setVisible(false);
        ui->editIP->setVisible(false);
        ui->editUserName->setVisible(false);
        ui->editPort->setVisible(false);
        ui->editPassword->setVisible(false);
    }
    else{
        ui->label_2->setVisible(true);
        ui->label_4->setVisible(true);
        ui->label_5->setVisible(true);
        ui->label_3->setVisible(true);
        ui->editIP->setVisible(true);
        ui->editUserName->setVisible(true);
        ui->editPort->setVisible(true);
        ui->editPassword->setVisible(true);
    }
}


void CameraDetailDialog::on_cmbBand_currentIndexChanged(int index)
{
    if(ui->cmbType->currentText()=="USBCamera" && index>=0){
        ui->editName->setText(ui->cmbBand->currentText());
        mCam->setCurrentCameraIndex(index);
    }
}

