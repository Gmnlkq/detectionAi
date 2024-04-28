#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimeEdit>
#include <QListWidget>
#include <QPoint>
#include "config.h"
class LeftWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LeftWidget(QWidget *parent = nullptr);
    ~LeftWidget();
    void initForm();
    void initWidget();
signals:

public slots:
    void slotShowPoint(MyPoint& pos);
    void slotGetNum(int num);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    void freeHBLay();
    void setScoreFormType();
private:
    QLabel* m_scoreLab=nullptr;
    QDoubleSpinBox* m_scoreDoubBox=nullptr;
    QLabel* m_algotithName=nullptr;
    QComboBox* m_algComBox=nullptr;
    QLabel* m_pointLab=nullptr;
    QLabel* m_x1Lab=nullptr;
    QLabel* m_x2Lab=nullptr;
    QLineEdit* m_x1LineEdit=nullptr;
    QLineEdit* m_x2LineEdit=nullptr;
    QLabel* m_y1Lab=nullptr;
    QLabel* m_y2Lab=nullptr;
    QLineEdit* m_y1LineEdit=nullptr;
    QLineEdit* m_y2LineEdit=nullptr;
    QLabel* m_algTimeLab=nullptr;
    QTimeEdit* m_algTimeEdit=nullptr;
    QLabel* m_alarmLab=nullptr;
    QLabel* m_detectLab=nullptr;
    QLineEdit* m_detectEdit=nullptr;
    QListWidget* m_alarmListWidget=nullptr;
    QVBoxLayout* m_mainLayout=nullptr;
    QVector<QHBoxLayout*> m_hbLayVector;
};

#endif // LEFTWIDGET_H
