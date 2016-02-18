#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QLCDNumber>
#include <QToolBar>
#include <QAction>
#include <QTimer>
#include <QListWidget>
#include <QStringList>

namespace Ui {
class stopWatch;
}

class stopWatch : public QLCDNumber
{
    Q_OBJECT
    
    QAction *startAction = new QAction(this);
    QAction *pauseAction = new QAction(this);
    QAction *resetAction = new QAction(this);
    QAction *lapAction = new QAction(this);
    
    QToolBar *bar = new QToolBar(this);
    
    long min,sec,msec;
    QString time;
    
    QTimer *timer = new QTimer(this);
       QListWidget *view=new QListWidget(this);
    
public slots:
    void resetTime();
    void startTime();
    void pauseTime();
    void updateTime();
    void lapTime();

public:
    explicit stopWatch(QWidget *parent = 0);
    void showTime();
    void resetLapTime();
    ~stopWatch();
};

#endif // STOPWATCH_H
