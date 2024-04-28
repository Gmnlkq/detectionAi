#include "work.h"
#include <QDebug>
#include "inference.h"
#include <QCoreApplication>

Work::Work(QObject *parent)
    : QObject{parent}
{
    initConnect();
}

void Work::initConnect()
{
    // connect(this,&Work::signalStop,this,&Work::slotStop);
}

void Work::slotStop(VideoStruct stop)
{
    stop.isStop = true;
    m_vStru = stop;
    qDebug()<<" stop----------2: ";
}

void Work::doWork(VideoStruct video)
{
    qDebug()<<"-----------------thread";
    m_vStru = video;
    bool runOnGPU = false;
    Inference inf(m_vStru.modelPath.toStdString(), cv::Size(640, 480), "classes.txt", runOnGPU);
    cv::Mat frame;
    cv::VideoCapture cap(m_vStru.videoPath.toStdString());
    if(!cap.isOpened())
    {
        // QMessageBox::warning(this,"警告","请重新添加视频文件(.mp4)");
        qDebug()<<"video path is vaild";
        return;
    }
    while(cap.read(frame) && !m_vStru.isStop )
    {
        QCoreApplication::processEvents();
        std::vector<Detection> output = inf.runInference(frame);
        int detections = output.size();
        // std::cout << "Number of detections:" << detections << std::endl;

        for (int i = 0; i < detections; ++i)
        {
            Detection detection = output[i];

            cv::Rect box = detection.box;
            cv::Scalar color = detection.color;

            // Detection box
            cv::rectangle(frame, box, color, 2);

            // Detection box text
            std::string classString = detection.className + ' ' + std::to_string(detection.confidence).substr(0, 4);
            cv::Size textSize = cv::getTextSize(classString, cv::FONT_HERSHEY_DUPLEX, 1, 2, 0);
            cv::Rect textBox(box.x, box.y - 40, textSize.width + 10, textSize.height + 20);

            cv::rectangle(frame, textBox, color, cv::FILLED);
            cv::putText(frame, classString, cv::Point(box.x + 5, box.y - 10), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 0), 2, 0);
        }
        emit resultReady(frame,detections);
        // emit sendFrame(frame);
        // emit signalNum(detections);
    }
    cap.release();
    qDebug()<<"视频已结束或中途发送了停止信号";
    emit signalExit();
    return;
}
