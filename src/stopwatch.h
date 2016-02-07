#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QLCDNumber>
#include <QToolBar>
#include <QAction>

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
    
    QString min,sec,time;
    

public:
    explicit stopWatch(QWidget *parent = 0);
    void showTime();
    ~stopWatch();
};

#endif // STOPWATCH_H
