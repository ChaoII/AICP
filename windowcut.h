#ifndef WINDOWCUT_H
#define WINDOWCUT_H

#include <QWidget>

namespace Ui {
class WindowCut;
}

class WindowCut : public QWidget
{
    Q_OBJECT

public:
    explicit WindowCut(QWidget *parent = nullptr);
    void clearAllSelectStatus();
    ~WindowCut();
signals:
    void windowCutStatusIndex(int index);


private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::WindowCut *ui;
};

#endif // WINDOWCUT_H
