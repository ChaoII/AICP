#include "imagehelper.h"
#include <QDebug>
using namespace cv;

ImageHelper::ImageHelper(QObject *parent) : QObject(parent)
{

}

QImage ImageHelper::Mat2QImg(Mat srcImage) {

    int channel;
    QImage image;
    if (!srcImage.empty()) {
        channel = srcImage.channels();
    }
    else {
        return image;
    }

    if (channel == 3) {
//        cvtColor(srcImage, srcImage, COLOR_BGR2RGB);
        image = QImage(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step, QImage::Format_BGR888);
    }
    else if (channel == 4) {
        cvtColor(srcImage, srcImage, COLOR_BGRA2RGB);
        image=QImage(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step,QImage::Format_RGB888);
    }
    else
    {
        image= QImage(srcImage.data,srcImage.cols, srcImage.rows, QImage::Format_Grayscale8);
    }
    return image;
}
