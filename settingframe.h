#ifndef SETTINGFRAME_H
#define SETTINGFRAME_H

#include <QWidget>

namespace Ui {
class SettingFrame;
}

class SettingFrame : public QWidget
{
    Q_OBJECT

public:
    explicit SettingFrame(QWidget *parent = nullptr);
    ~SettingFrame();

private:
    Ui::SettingFrame *ui;
};

#endif // SETTINGFRAME_H
