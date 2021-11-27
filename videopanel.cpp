#include "videopanel.h"
#include "ui_videopanel.h"
#include <QMenu>

VideoPanel::VideoPanel(QWidget *parent) :QWidget(parent),ui(new Ui::VideoPanel)
{
    ui->setupUi(this);
    initForm();
    ui->actionNormal->setEnabled(false);
    ui->action_1->setEnabled(false);
}

VideoPanel::~VideoPanel()
{
    delete ui;

}

QList<VideoLabel *> VideoPanel::getLabelPanel()
{
    return mVideoPanel;
}



void VideoPanel::initForm()
{
    gridLayout = new QGridLayout;
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setObjectName("gridLayout");
    this->setLayout(gridLayout);

    for(int i =0;i<mMaxVideoWidgets;i++){
        VideoLabel *label = new VideoLabel;
        QStringList qss;
        label->setObjectName(QString("video%1").arg(i + 1));
        label->setText(QString("视频%1").arg(i + 1));
        connect(label,&VideoLabel::doubleClicked,this,&VideoPanel::on_videoLabelDubleClicked);
        mVideoPanel.append(label);
    }
    gridLayout->addWidget(mVideoPanel.at(0));
    mVideoPanel.at(0)->setVisible(true);
}

void VideoPanel::hideAll()
{
    for(int i=0;i<mMaxVideoWidgets;i++){
        gridLayout->removeWidget(mVideoPanel.at(i));
        mVideoPanel.at(i)->setVisible(false);
    }
}

void VideoPanel::on_VideoPanel_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
//    QMenu* menue =new QMenu(this);
//    QStringList qss;
//    qss.append("QMenu{background-color:#303030;color:#F0F0F0}");
//    qss.append("QMenu:pressed{color:555555}");
//    qss.append("QMenu:disabled{color:#b0b0b0;}");
//    menue->addAction(ui->action_1);
//    menue->addAction(ui->action_4);
//    menue->addAction(ui->action_6);
//    menue->addAction(ui->action_9);
//    menue->addSeparator();
//    menue->addAction(ui->actionFullScreen);
//    menue->addAction(ui->actionNormal);
//    menue->setStyleSheet(qss.join(""));
//    menue->exec(QCursor::pos());
}


void VideoPanel::changeWindowCut1()
{
    hideAll();
//    setActionSelected(labelNums);
    gridLayout->addWidget(mVideoPanel.at(0));
    mVideoPanel.at(0)->setVisible(true);
}

void VideoPanel::changeWindowCut4()
{
    hideAll();
    //    QAction* action = static_cast<QAction*>(sender());
    //    int labelNums = action->objectName().split("_")[1].toInt();
    int labelNums=4;
//    setActionSelected(labelNums);
    int rowColCount = qSqrt(labelNums);
    for (int i =0;i<labelNums;i++){

        gridLayout->addWidget(mVideoPanel.at(i),i/rowColCount,i%rowColCount);
        mVideoPanel.at(i)->setVisible(true);
    }
    //    this->setLayout(mLayOut);
}



void VideoPanel::changeWindowCut6()
{
    hideAll();
    int labelNums=6;
    gridLayout->addWidget(mVideoPanel.at(0), 0, 0, 2, 2);
    gridLayout->addWidget(mVideoPanel.at(1), 0, 2, 1, 1);
    gridLayout->addWidget(mVideoPanel.at(2), 1, 2, 1, 1);
    gridLayout->addWidget(mVideoPanel.at(3), 2, 2, 1, 1);
    gridLayout->addWidget(mVideoPanel.at(4), 2, 1, 1, 1);
    gridLayout->addWidget(mVideoPanel.at(5), 2, 0, 1, 1);
    for(int i = 0;i<labelNums;i++){
        mVideoPanel.at(i)->setVisible(true);
    }
}

void VideoPanel::changeWindowCut9()
{
    hideAll();
    int labelNums=9;
//    setActionSelected(labelNums);
    int rowColCount = qSqrt(labelNums);
    for (int i =0;i<labelNums;i++){
        gridLayout->addWidget(mVideoPanel.at(i),i/rowColCount,i%rowColCount);
        mVideoPanel.at(i)->setVisible(true);
    }
    //    this->setLayout(mLayOut);
}

void VideoPanel::on_videoLabelDubleClicked()
{
    VideoLabel * label = static_cast<VideoLabel*>(sender());
    hideAll();
    gridLayout->addWidget(label);
    label->setVisible(true);

}

void VideoPanel::keyPressEvent(QKeyEvent *event)
{
    if((event->key()==Qt::Key_Escape)&&this->windowState()==Qt::WindowFullScreen){
        this->setWindowFlags(Qt::SubWindow);
        this->showNormal();
    }
}

