#ifndef IMAGEHELPER_H
#define IMAGEHELPER_H

#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/videoio.hpp>


class ImageHelper : public QObject
{
    Q_OBJECT
public:
    explicit ImageHelper(QObject *parent = nullptr);
    QImage Mat2QImg(cv::Mat srcImage);

signals:

};

#endif // IMAGEHELPER_H
