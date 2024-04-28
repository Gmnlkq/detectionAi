#ifndef WORK_H
#define WORK_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include "config.h"

class Work : public QObject
{
    Q_OBJECT
public:
    explicit Work(QObject *parent = nullptr);
    void initConnect();
signals:
    void resultReady(cv::Mat mat,int num);
    void signalStop(VideoStruct video);
    void signalExit();
    // void signalStop(int val);
public slots:
    void doWork(VideoStruct video);
    // void slotStop(int val);
    void slotStop(VideoStruct stop);
private:
    VideoStruct m_vStru;
};

#endif // WORK_H
