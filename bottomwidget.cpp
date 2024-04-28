#include "bottomwidget.h"
#include <QPainter>
#include <QDebug>
#include <QPixmap>
#include "config.h"
#include <QFileDialog>
#include <QMessageBox>
#include "inference.h"
#include <QTimer>

BottomWidget::BottomWidget(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<VideoStruct>("VideoStruct");
    initWidget();
    initForm();
    initConnect();
}

BottomWidget::~BottomWidget()
{
    deleteVbLay();
    // m_workThread.quit();
    // m_workThread.wait();
}

void BottomWidget::initForm()
{
    setMaximumHeight(bottWidgetHeight);
    m_startPtn->setText("开始");
    m_clearPtn->setText("清除记录");
    m_capPtn->setText("抓拍");
    m_stopPtn->setText("停止");
    m_addPtn->setText("添加图片");
    m_addModelPtn->setText("添加模型");
    m_addVideoPtn->setText("添加视频");
    m_picChBox->setText("图片模式");
    m_videoChBox->setText("视频模式");
    m_addPtn->setDisabled(true);
    m_addVideoPtn->setDisabled(true);
    m_capPtn->setDisabled(true);
}

void BottomWidget::initWidget()
{
    m_mainLayout = new QHBoxLayout(this);
    QVBoxLayout* vbLay1 = new QVBoxLayout();
    m_capPtn = new QPushButton(this);
    m_clearPtn = new QPushButton(this);
    vbLay1->addWidget(m_capPtn);
    vbLay1->addWidget(m_clearPtn);
    m_vecVlay.push_back(vbLay1);
    m_picChBox = new QCheckBox(this);
    m_videoChBox = new QCheckBox(this);
    QVBoxLayout* vbLay2 = new QVBoxLayout();
    vbLay2->addWidget(m_picChBox);
    vbLay2->addWidget(m_videoChBox);
    m_vecVlay.push_back(vbLay2);
    m_addVideoPtn = new QPushButton(this);
    m_addPtn = new QPushButton(this);
    QVBoxLayout* vbLay3 = new QVBoxLayout();
    vbLay3->addWidget(m_addVideoPtn);
    vbLay3->addWidget(m_addPtn);
    m_vecVlay.push_back(vbLay3);
    m_addModelPtn = new QPushButton(this);
    QVBoxLayout* vbLay4 = new QVBoxLayout();
    vbLay4->addWidget(m_addModelPtn);
    m_vecVlay.push_back(vbLay4);
    m_startPtn = new QPushButton(this);
    m_stopPtn = new QPushButton(this);
    QVBoxLayout* vbLay5 = new QVBoxLayout();
    vbLay5->addWidget(m_startPtn);
    vbLay5->addWidget(m_stopPtn);
    m_vecVlay.push_back(vbLay5);
    m_mainLayout->addLayout(vbLay1);
    m_mainLayout->addLayout(vbLay2);
    m_mainLayout->addLayout(vbLay3);
    m_mainLayout->addLayout(vbLay4);
    m_mainLayout->addLayout(vbLay5);
    m_mainLayout->setContentsMargins(0,0,0,0);
    setContentsMargins(0,0,0,0);
}

void BottomWidget::initConnect()
{
    connect(m_addPtn,&QPushButton::clicked,this,\
          &BottomWidget::slotsAddPicture);
    connect(m_addModelPtn,&QPushButton::clicked,this,\
            &BottomWidget::slotsAddModel);
    connect(m_startPtn,&QPushButton::clicked,this,\
            &BottomWidget::slotsInference);
    connect(m_addVideoPtn,&QPushButton::clicked,this,\
            &BottomWidget::slotsAddVideo);
    connect(m_videoChBox,&QCheckBox::clicked,this,\
            &BottomWidget::slotCheckVideo);
    connect(m_picChBox,&QCheckBox::clicked,this,\
            &BottomWidget::slotCheckPicture);
    connect(m_capPtn,&QPushButton::clicked,this,\
            &BottomWidget::slotCapFrame);
    connect(m_stopPtn,&QPushButton::clicked,this,\
            &slotStopVideo);
}

void BottomWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void BottomWidget::slotsAddPicture()
{
    m_imgPath =  QFileDialog::getOpenFileName();
    if(m_imgPath.isEmpty())
    {
        QMessageBox::warning(this,"警告","请添加图片");
    }
    else
    {
        m_vecPath.push_back(m_imgPath.toStdString());
    }
}

void BottomWidget::slotsAddModel()
{
    m_modelPath =  QFileDialog::getOpenFileName();
    m_videoStrc.modelPath = m_modelPath;
    if(m_modelPath.isEmpty())
    {
        QMessageBox::warning(this,"警告","请添加模型");
    }
    return;
}

void BottomWidget::slotsAddVideo()
{
    m_videoPath =  QFileDialog::getOpenFileName();
    m_videoStrc.videoPath = m_videoPath;
    m_videoStrc.isStop = false;
    if(m_videoPath.isEmpty())
    {
        QMessageBox::warning(this,"警告","请添加视频文件");
    }
    return;
}

void BottomWidget::slotsInference()
{
    bool runOnGPU = false;
    if(m_myType == PICTURE)
    {
        if(m_vecPath.empty() || m_modelPath.isEmpty())
        {
            QMessageBox::warning(this,"警告","没有添加图片或模型");
            return;
        }
    }
    if(m_myType == VIDEO)
    {
        if(m_videoPath.isEmpty() || m_modelPath.isEmpty())
        {
            QMessageBox::warning(this,"警告","没有添加视频或模型");
            return;
        }
    }
    Inference inf(m_modelPath.toStdString(), cv::Size(640, 480), "classes.txt", runOnGPU);
    if(PICTURE == m_myType)
    {
        for(int i=0; i<m_vecPath.size(); i++)
        {
            cv::Mat frame = cv::imread(m_vecPath[i]);
            std::vector<Detection> output = inf.runInference(frame);
            int detections = output.size();
            std::cout << "Number of detections:" << detections << std::endl;

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
            emit sendFrame(frame);
            emit signalNum(detections);
        }
    }
    else
    {
        //dowork
        m_worker = new Work();
        m_worker->moveToThread(&m_workThread);
        //stop
        connect(this,&BottomWidget::signalStop,m_worker,&Work::slotStop);
        connect(this,&BottomWidget::startRunning,m_worker,&Work::doWork);
        connect(&m_workThread,&QThread::finished,m_worker,&QObject::deleteLater);
        connect(m_worker,&Work::resultReady,this,&BottomWidget::receivResult);
        connect(m_worker,&Work::signalExit,this,&BottomWidget::slotExit);
        emit startRunning(m_videoStrc);
        m_workThread.start();
    }
}

void BottomWidget::deleteVbLay()
{
    if(!m_vecVlay.isEmpty())
    {
        for(auto& vb: m_vecVlay)
        {
            if(NULL != vb)
            {
                delete vb;
                vb = NULL;
            }
        }
    }
}

void BottomWidget::receivResult(cv::Mat mat,int num)
{
    emit sendFrame(mat);
    emit signalNum(num);
}

void BottomWidget::slotCheckVideo(int val)
{
    qDebug()<<"val "<<val;
    if(val == Qt::PartiallyChecked)
    {
        m_addVideoPtn->setDisabled(false);
        m_capPtn->setDisabled(false);
        m_myType = VIDEO;
    }
    else if(val == Qt::Unchecked)
    {
        m_addVideoPtn->setDisabled(true);
        m_capPtn->setDisabled(true);
        m_myType = -1;
    }
}

void BottomWidget::slotCheckPicture(int val)
{
    qDebug()<<"val "<<val;
    if(val == Qt::PartiallyChecked)
    {
        m_addPtn->setDisabled(false);
        m_myType = PICTURE;
    }
    else if(val == Qt::Unchecked)
    {
        m_addPtn->setDisabled(true);
        m_myType = -1;
    }
}

void BottomWidget::slotCapFrame()
{
    cv::Mat frame;
    if(m_videoPath.isEmpty())
    {
        QMessageBox::warning(this,"警告","请添加视频文件(.mp4)");
        return;
    }
    cv::VideoCapture cap(m_videoPath.toStdString());
    if(!cap.isOpened())
    {
        QMessageBox::warning(this,"警告","mp4文件有误，请重新添加");
        return;
    }
    cap.read(frame);
    cap.release();
    emit sendFrame(frame);
}

void BottomWidget::slotStopVideo()
{
    emit signalStop(m_videoStrc);
    qDebug()<<" stop----------1";
}

void BottomWidget::slotExit()
{
    if(m_workThread.isRunning())
    {
        m_workThread.quit();
        m_workThread.wait();
        qDebug()<<"线程已退出";
    }
}
