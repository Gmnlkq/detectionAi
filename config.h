#ifndef CONFIG_H
#define CONFIG_H
#include <QString>
#include <QPoint>

extern QString strWindowTitle;
extern qint32 mainWidgetWidth;
extern qint32 mainWidgetHeight;
extern qint32 leftWidgetWidth;
extern qint32 displayWidgetHeight;
extern qint32 displayWidgetWidth;
extern qint32 bottWidgetHeight;
extern qint32 bottWidgetWidth;

typedef struct MyPoint{
    QPoint m_leftTopPoint;
    QPoint m_rightBottomPoint;
}MyPoint;

typedef enum RunType{
    PICTURE = 0,
    VIDEO =1,
}RunType;

typedef struct VideoStruct
{
    QString videoPath;
    QString modelPath;
    bool isStop;
}VideoStruct;

#endif // CONFIG_H
