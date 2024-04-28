#include "widget.h"
#include "leftwidget.h"
#include "bottomwidget.h"
#include "displayshow.h"
#include "config.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initWidget();
    initForm();
    initConnect();
}

Widget::~Widget()
{
}

void Widget::initForm()
{
    setWindowTitle(strWindowTitle);
//    setMinimumSize(mainWidgetWidth,mainWidgetHeight);
}

void Widget::initWidget()
{
    m_mainLayout = new QHBoxLayout(this);
    m_vbLayout = new QVBoxLayout();
    m_bottWid = new BottomWidget(this);
    m_leftWid =  new LeftWidget(this);
    m_disShow =  new DisplayShow(this);
    m_vbLayout->addWidget(m_disShow);
    m_vbLayout->addWidget(m_bottWid);
    m_vbLayout->setContentsMargins(0,0,0,0);
    m_vbLayout->setSpacing(0);
    m_mainLayout->addWidget(m_leftWid);
    m_mainLayout->addLayout(m_vbLayout);
    m_mainLayout->setContentsMargins(0,0,0,0);
    m_mainLayout->setSpacing(0);
}

void Widget::initConnect()
{
    connect(m_bottWid,&BottomWidget::sendFrame,m_disShow,&DisplayShow::recvFrame);
    connect(m_disShow,&DisplayShow::signalPosition,m_leftWid,\
                            &LeftWidget::slotShowPoint);
    connect(m_bottWid,&BottomWidget::signalNum,m_leftWid,\
                            &LeftWidget::slotGetNum);
}
