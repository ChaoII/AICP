#include "windowcut.h"
#include "ui_windowcut.h"

WindowCut::WindowCut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowCut)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_QuitOnClose,false);
}

void WindowCut::clearAllSelectStatus()
{
    ui->toolButton->setChecked(false);
    ui->toolButton_2->setChecked(false);
    ui->toolButton_3->setChecked(false);
    ui->toolButton_4->setChecked(false);
}

WindowCut::~WindowCut()
{
    qDebug()<<"析构了";
    delete ui;
}

void WindowCut::on_toolButton_clicked()
{
    clearAllSelectStatus();
    ui->toolButton->setChecked(true);
    emit windowCutStatusIndex(1);
}


void WindowCut::on_toolButton_2_clicked()
{
    clearAllSelectStatus();
    ui->toolButton_2->setChecked(true);
    emit windowCutStatusIndex(4);
}


void WindowCut::on_toolButton_3_clicked()
{
    clearAllSelectStatus();
    ui->toolButton_3->setChecked(true);
    emit windowCutStatusIndex(6);
}


void WindowCut::on_toolButton_4_clicked()
{
    clearAllSelectStatus();
    ui->toolButton_4->setChecked(true);
    emit windowCutStatusIndex(9);
}

