#include "displayshow.h"
#include <QPainter>
#include <QDebug>
#include "config.h"

DisplayShow::DisplayShow(QWidget *parent)
    : QWidget(parent)
{
    initForm();
}

void DisplayShow::initForm()
{
//    setMinimumSize(displayWidgetWidth,displayWidgetHeight);
}

void DisplayShow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/3.jpg");
//    pix = pix.scaled(displayWidgetWidth,displayWidgetHeight);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    if(m_bframe)
    {
        painter.drawPixmap(0,0,this->width(),this->height(),m_pix);
        m_bframe = false;
    }
    if(m_rec)
    {
        QRect rec(m_pointPress,m_pointMove);
        painter.drawRect(rec);
        m_rec = false;
        qDebug()<<"painter rec frame";
    }
}

// 将Mat转化位QImage
QImage cvMatToQImage( const cv::Mat &inMat )
{
    switch ( inMat.type() )
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image( inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_ARGB32 );

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image( inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_RGB888 );

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image( inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_Grayscale8 );//Format_Alpha8 and Format_Grayscale8 were added in Qt 5.5
#else//这里还有一种写法，最后给出
        static QVector<QRgb>  sColorTable;

        // only create our color table the first time
        if ( sColorTable.isEmpty() )
        {
            sColorTable.resize( 256 );

            for ( int i = 0; i < 256; ++i )
            {
                sColorTable[i] = qRgb( i, i, i );
            }
        }

        QImage image( inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_Indexed8 );

        image.setColorTable( sColorTable );
#endif

        return image;
    }

    default:
        qWarning() << "CVS::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
        break;
    }

    return QImage();
}

QPixmap cvMatToQPixmap( const cv::Mat &inMat )
{
    return QPixmap::fromImage(cvMatToQImage(inMat));
}

void DisplayShow::recvFrame(cv::Mat mat)
{
    if(mat.empty())
    {
        qDebug()<<"mat is empty";
        return;
    }
    m_pix = cvMatToQPixmap(mat);
    m_bframe = true;
    update();
}

void DisplayShow::mousePressEvent(QMouseEvent *event)
{
    m_pointPress = event->pos();
    qDebug()<<"press m_point_x "<<m_pointPress.x();
    qDebug()<<"press m_point_x "<<m_pointPress.y();
}

void DisplayShow::mouseReleaseEvent(QMouseEvent *event)
{
    m_pointRelease = event->pos();
    m_myPoint.m_leftTopPoint = m_pointPress;
    m_myPoint.m_rightBottomPoint = m_pointRelease;
    emit signalPosition(m_myPoint);
}

void DisplayShow::mouseMoveEvent(QMouseEvent *event)
{
    m_pointMove = event->pos();
    qDebug()<<"move m_point_x "<<m_pointMove.x();
    qDebug()<<"move m_point_x "<<m_pointMove.y();
    m_rec = true;
    update();
}
