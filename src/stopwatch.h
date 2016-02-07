#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QLCDNumber>
#include <QToolBar>
#include <QAction>
#include <QTimer>

namespace Ui {
class stopWatch;
}

class stopWatch : public QLCDNumber
{
    Q_OBJECT
    
    QAction *startAction = new QAction(this);
    QAction *pauseAction = new QAction(this);
    QAction *resetAction = new QAction(this);
    
    QToolBar *bar = new QToolBar(this);
    
    long min,sec,msec;
    QString time;
    
    QTimer *timer = new QTimer(this);
    
    
public slots:
    void resetTime();
    void startTime();
    void pauseTime();
    void updateTime();
    

public:
    explicit stopWatch(QWidget *parent = 0);
    void showTime();
    ~stopWatch();
};

#endif // STOPWATCH_H
