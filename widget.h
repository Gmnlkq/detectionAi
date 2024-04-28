#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

class BottomWidget;
class LeftWidget;
class DisplayShow;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void initForm();
    void initWidget();
    void initConnect();
private:
    QHBoxLayout* m_mainLayout=nullptr;
    QVBoxLayout* m_vbLayout=nullptr;
    BottomWidget* m_bottWid=nullptr;
    LeftWidget* m_leftWid=nullptr;
    DisplayShow* m_disShow=nullptr;
};

#endif // WIDGET_H
