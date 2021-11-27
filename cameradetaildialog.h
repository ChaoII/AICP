#ifndef CAMERADETAILDIALOG_H
#define CAMERADETAILDIALOG_H
#include "camera.h"
#include <QDialog>

namespace Ui {
class CameraDetailDialog;
}

class CameraDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CameraDetailDialog(QWidget *parent = nullptr);
    ~CameraDetailDialog();
signals:
    void sendCameraDetail(Camera *camera);
private slots:
    void on_buttonBox_accepted();

    void on_cmbType_currentTextChanged(const QString &arg1);

    void on_cmbBand_currentTextChanged(const QString &arg1);

    void on_cmbBand_currentIndexChanged(int index);

private:
    Ui::CameraDetailDialog *ui;
    QCameraDevice  mCurrentCameraDevice =  QMediaDevices::defaultVideoInput();
    Camera* mCam;
    bool isCorrectSend=false;
};

#endif // CAMERADETAILDIALOG_H
