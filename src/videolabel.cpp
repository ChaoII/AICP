#include "videolabel.h"

VideoLabel::VideoLabel(QWidget *parent) :QLabel(parent)
{
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




