#ifndef VIDEOPANEL_H
#define VIDEOPANEL_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QSizePolicy>
#include <QMouseEvent>
#include "videolabel.h"

namespace Ui {
class VideoPanel;
}

class VideoPanel : public QWidget
{
    Q_OBJECT

public:
    explicit VideoPanel(QWidget *parent = nullptr);
    ~VideoPanel();
    QList<VideoLabel*> getLabelPanel();
    void initForm();
    void hideAll();
    void changeWindowCut1();
    void changeWindowCut4();
    void changeWindowCut6();
    void changeWindowCut9();
    void on_action_9_triggered();
    void on_action_6_triggered();
    void on_action_4_triggered();
    int mMaxVideoWidgets=9;
protected:
    virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_VideoPanel_customContextMenuRequested(const QPoint &pos);

    void on_videoLabelDubleClicked();





private:
    Ui::VideoPanel *ui;
    QGridLayout *gridLayout;
    QList<VideoLabel*> mVideoPanel;
    bool mIsFullScreen=false;
    QString mCurreentShowText;
};

#endif // VIDEOPANEL_H
