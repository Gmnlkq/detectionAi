#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <QCheckBox>
#include <QVector>
#include "config.h"
#include <QThread>
#include "work.h"

class BottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = nullptr);
    ~BottomWidget();
    void initForm();
    void initWidget();
    void initConnect();
signals:
    void sendFrame(cv::Mat mat);
    void signalNum(int val);
    void startRunning(VideoStruct video);
    void signalStop(VideoStruct video);
    // void signalStop(int val);
public slots:
    void slotsAddPicture();
    void slotsInference();
    void slotsAddModel();
    void slotsAddVideo();
    void receivResult(cv::Mat mat,int num);
private slots:
    void slotCheckVideo(int val);
    void slotCheckPicture(int val);
    void slotCapFrame();
    void slotStopVideo();
    void slotExit();
protected:
    void paintEvent(QPaintEvent *event);
private:
    void deleteVbLay();
private:
    QHBoxLayout* m_mainLayout=nullptr;
    QPushButton* m_startPtn=nullptr;
    QPushButton* m_stopPtn=nullptr;
    QPushButton* m_clearPtn=nullptr;
    QPushButton* m_capPtn=nullptr;
    QPushButton* m_addPtn=nullptr;
    QPushButton* m_addModelPtn=nullptr;
    QPushButton* m_addVideoPtn=nullptr;
    QCheckBox* m_picChBox=nullptr;
    QCheckBox* m_videoChBox=nullptr;
    QString m_imgPath;
    QString m_videoPath;
    std::vector<std::string> m_vecPath;
    QString m_modelPath;
    qint32 m_myType = 0;
    QVector<QVBoxLayout*> m_vecVlay;
    VideoStruct m_videoStrc;
    //thread
    QThread m_workThread;
    Work *m_worker;
};

#endif // BOTTOMWIDGET_H
