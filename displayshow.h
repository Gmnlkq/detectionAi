#ifndef DISPLAYSHOW_H
#define DISPLAYSHOW_H

#include <QWidget>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include "config.h"

class DisplayShow : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayShow(QWidget *parent = nullptr);
    void initForm();
    void initConnect();
signals:
    void signalPosition(MyPoint& pos);
public slots:
    void recvFrame(cv::Mat mat);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QPixmap m_pix;
    bool m_bframe = false;
    bool m_rec = false;
    QPoint m_pointPress;
    QPoint m_pointRelease;
    QPoint m_pointMove;
    MyPoint m_myPoint;
};

#endif // DISPLAYSHOW_H
