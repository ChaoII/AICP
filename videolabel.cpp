#include "videolabel.h"

VideoLabel::VideoLabel(QWidget *parent) :QLabel(parent)
{
    QStringList qss;
//    qss.append("QLabel{font:40 18px;color:#F0F0F0;border:1px solid #AAAAAA;background:#303030;}");
    qss.append("QLabel{font:40 15px;color:#B4B4B4;border:1px solid #181818;background:#303030;}");
//    qss.append("QLabel:focus{border:1px solid #00BB9E;background:#555555;}");
    qss.append("QLabel:focus{border:1px solid red;background:#555555;}");
    this->setStyleSheet(qss.join(""));
    this->setFocusPolicy(Qt::StrongFocus);
    this->setAlignment(Qt::AlignCenter);
    this->setAcceptDrops(true);
    this->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
}

VideoLabel::~VideoLabel()
{

}

void VideoLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit doubleClicked();
    QLabel::mouseDoubleClickEvent(event);
}




