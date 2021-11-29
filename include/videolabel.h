#ifndef VIDEOLABEL_H
#define VIDEOLABEL_H

#include <QLabel>
#include <QToolButton>
#include <QPaintEvent>

class VideoLabel : public QLabel
{
    Q_OBJECT

public:
    explicit VideoLabel(QWidget *parent = nullptr);
    ~VideoLabel();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
signals:
    void doubleClicked();
};

#endif // VIDEOLABEL_H
