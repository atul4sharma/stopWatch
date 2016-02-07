#include "stopwatch.h"
//#include "ui_stopwatch.h"

#include <QTimer>

stopWatch::stopWatch(QWidget *parent) :
    QLCDNumber(parent),
    min(0),
    sec(0)
{   
    startAction->setText("Start");
    pauseAction->setText("Pause");
    resetAction->setText("Reset");
    
    bar->addAction(startAction);
    bar->addAction(pauseAction);
    bar->addAction(resetAction);
    
    connect(startAction,SIGNAL(triggered()),SLOT(startTime()));
    connect(pauseAction,SIGNAL(triggered()),SLOT(pauseTime()));
    connect(resetAction,SIGNAL(triggered()),SLOT(resetTime()));
    connect(timer,SIGNAL(timeout()),SLOT(updateTime()));
    
        
    showTime();
    resize(180,150);
}

stopWatch::~stopWatch()
{
  
}

void stopWatch::showTime()
{   time = QString::number(min)+":"+QString::number(sec);
    this->display(time);
}

void stopWatch::resetTime()
{   min=0;
    sec=0;
    showTime();
}

void stopWatch::pauseTime()
{   
    timer->stop();
}

void stopWatch::startTime()
{
    timer->start(1000);
}

void stopWatch::updateTime()
{   
   sec+=1;

    if(sec==60)
    {
        min+=1;
        sec=0;
    }
    showTime();
}
