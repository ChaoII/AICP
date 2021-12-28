#include "settingframe.h"
#include "ui_settingframe.h"

SettingFrame::SettingFrame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingFrame)
{
    ui->setupUi(this);
}

SettingFrame::~SettingFrame()
{
    delete ui;
}
