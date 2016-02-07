#include "stopwatch.h"
//#include "ui_stopwatch.h"

#include <QTimer>

stopWatch::stopWatch(QWidget *parent) :
    QLCDNumber(parent),
    min("00"),
    sec("00")
{   
    startAction->setText("Start");
    pauseAction->setText("Pause");
    resetAction->setText("Reset");
    
    bar->addAction(startAction);
    bar->addAction(pauseAction);
    bar->addAction(resetAction);
    
    showTime();
    
    resize(180,150);
}

stopWatch::~stopWatch()
{
  
}

void stopWatch::showTime()
{
    time = min+":"+sec;
    this->display(time);
}
