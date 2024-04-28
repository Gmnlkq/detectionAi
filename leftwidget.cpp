#include "leftwidget.h"
#include "config.h"
#include <QPainter>
#include <QDebug>

LeftWidget::LeftWidget(QWidget *parent)
    : QWidget(parent)
{
    initWidget();
    initForm();
}

void LeftWidget::initWidget()
{
    m_scoreLab = new QLabel(this);
    m_scoreDoubBox = new QDoubleSpinBox(this);
    QHBoxLayout* hblay1 = new QHBoxLayout();
    hblay1->addWidget(m_scoreLab);
    hblay1->addWidget(m_scoreDoubBox);
    hblay1->setContentsMargins(0,0,0,0);
    hblay1->setSpacing(0);
    m_hbLayVector.push_back(hblay1);
    m_algotithName = new QLabel(this);
    m_algComBox = new QComboBox(this);
    QHBoxLayout* hblay2 = new QHBoxLayout();
    hblay2->addWidget(m_algotithName);
    hblay2->addWidget(m_algComBox);
    hblay2->setContentsMargins(0,0,0,0);
    hblay2->setSpacing(0);
    m_hbLayVector.push_back(hblay2);
    m_algTimeLab = new QLabel(this);
    m_algTimeEdit = new QTimeEdit(QTime::currentTime(),this);
    QHBoxLayout* hblay3 = new QHBoxLayout();
    hblay3->addWidget(m_algTimeLab);
    hblay3->addWidget(m_algTimeEdit);
    hblay3->setContentsMargins(0,0,0,0);
    hblay3->setSpacing(0);
    m_hbLayVector.push_back(hblay3);
    m_pointLab = new QLabel(this);
    QHBoxLayout* hblay4 = new QHBoxLayout();
    hblay4->addWidget(m_pointLab);
    hblay4->addStretch();
    hblay4->setContentsMargins(0,0,0,0);
    hblay4->setSpacing(0);
    m_hbLayVector.push_back(hblay4);
    m_x1Lab = new QLabel(this);
    m_x1LineEdit = new QLineEdit(this);
    m_y1Lab = new QLabel(this);
    m_y1LineEdit = new QLineEdit(this);
    QHBoxLayout* hblay5 = new QHBoxLayout();
    hblay5->addWidget(m_x1Lab);
    hblay5->addWidget(m_x1LineEdit);
    hblay5->addWidget(m_y1Lab);
    hblay5->addWidget(m_y1LineEdit);
    hblay5->setContentsMargins(0,0,0,0);
    hblay5->setSpacing(0);
    m_hbLayVector.push_back(hblay5);
    m_x2Lab = new QLabel(this);
    m_x2LineEdit = new QLineEdit(this);
    m_y2Lab = new QLabel(this);
    m_y2LineEdit = new QLineEdit(this);
    QHBoxLayout* hblay6 = new QHBoxLayout();
    hblay6->addWidget(m_x2Lab);
    hblay6->addWidget(m_x2LineEdit);
    hblay6->addWidget(m_y2Lab);
    hblay6->addWidget(m_y2LineEdit);
    hblay6->setContentsMargins(0,0,0,0);
    hblay6->setSpacing(0);
    m_hbLayVector.push_back(hblay6);
    m_alarmLab = new QLabel(this);
    m_alarmListWidget = new QListWidget(this);
    QHBoxLayout* hblay7 = new QHBoxLayout();
    hblay7->addWidget(m_alarmLab);
    hblay7->addStretch();
    hblay7->setContentsMargins(0,0,0,0);
    m_hbLayVector.push_back(hblay7);
    QHBoxLayout* hblay8 = new QHBoxLayout();
    m_detectLab = new QLabel(this);
    m_detectEdit = new QLineEdit(this);
    hblay8->addWidget(m_detectLab);
    hblay8->addWidget(m_detectEdit);
    m_hbLayVector.push_back(hblay8);
    QHBoxLayout* hblay9 = new QHBoxLayout();
    hblay9->addWidget(m_alarmListWidget);
    hblay9->setContentsMargins(0,0,0,0);
    m_hbLayVector.push_back(hblay9);
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addLayout(hblay1);
    m_mainLayout->addLayout(hblay2);
    m_mainLayout->addLayout(hblay3);
    m_mainLayout->addLayout(hblay4);
    m_mainLayout->addLayout(hblay5);
    m_mainLayout->addLayout(hblay6);
    m_mainLayout->addLayout(hblay8);
    m_mainLayout->addLayout(hblay7);
    m_mainLayout->addLayout(hblay9);
    m_mainLayout->setContentsMargins(0,0,0,0);
    setContentsMargins(0,0,0,0);
}

void LeftWidget::initForm()
{
    setMaximumWidth(leftWidgetWidth);
    m_scoreLab->setText("置信度");
    m_algotithName->setText("算法名称");
    QStringList strList;
    strList<<"入侵检测"<<"摔倒检测"<<"岗点检测";
    m_algComBox->addItems(strList);
    m_algTimeLab->setText("时间");
    m_pointLab->setText("坐标点");
    m_x1Lab->setText("x1");
    m_y1Lab->setText("y1");
    m_x2Lab->setText("x2");
    m_y2Lab->setText("y2");
    m_alarmLab->setText("告警记录");
    m_detectLab->setText("检测目标数量:");
    setScoreFormType();
    m_algTimeEdit->setDisplayFormat(QString("HH:mm:ss"));
}

void LeftWidget::setScoreFormType()
{
    m_scoreDoubBox->setSingleStep(0.01);
    m_scoreDoubBox->setRange(0.00,1.00);
}

void LeftWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QPixmap pix(":/1.jpg");
//    pix = pix.scaled(leftWidgetWidth,this->height());
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void LeftWidget::freeHBLay()
{
    if(!m_hbLayVector.isEmpty())
    {
       for(auto& hb:m_hbLayVector)
       {
           if(NULL != hb)
           {
               delete hb;
               hb = NULL;
           }
       }
    }
}

LeftWidget::~LeftWidget()
{
    freeHBLay();
}

void LeftWidget::slotShowPoint(MyPoint& pos)
{
    m_x1LineEdit->setText(QString::number(pos.m_leftTopPoint.x()));
    m_y1LineEdit->setText(QString::number(pos.m_leftTopPoint.y()));
    m_x2LineEdit->setText(QString::number(pos.m_rightBottomPoint.x()));
    m_y2LineEdit->setText(QString::number(pos.m_rightBottomPoint.y()));
}

void LeftWidget::slotGetNum(int num)
{
    m_detectEdit->setText(QString::number(num));
}
