#include "stopwatch.h"
//#include "ui_stopwatch.h"
#include <QPushButton>
#include <QTimer>

stopWatch::stopWatch(QWidget *parent) :
    QLCDNumber(parent),
    min(0),
    sec(0),
    msec(0)
{  
    this->setDigitCount(7);
    startAction->setText("Start");
    pauseAction->setText("Pause");
    resetAction->setText("Reset");
    lapAction->setText("Lap");
    
    bar->addAction(startAction);
    bar->addAction(pauseAction);
    bar->addAction(resetAction);
    bar->addAction(lapAction);
    
    connect(startAction,SIGNAL(triggered()),SLOT(startTime()));
    connect(pauseAction,SIGNAL(triggered()),SLOT(pauseTime()));
    connect(resetAction,SIGNAL(triggered()),SLOT(resetTime()));
    connect(timer,SIGNAL(timeout()),SLOT(updateTime()));
    connect(lapAction,SIGNAL(triggered()),SLOT(lapTime()));
    
    view->hide();
        
    showTime();
    resize(220,165);
}

stopWatch::~stopWatch()
{
  
}

void stopWatch::showTime()
{  
    time = QString::number(min)+":"+QString::number(sec)+":"+QString::number(msec/100);
    this->display(time);
}

void stopWatch::resetLapTime()
{   min=0;
    sec=0;
    msec=0;
    showTime(); 
}

void stopWatch::resetTime()
{
    resetLapTime();
       this->pauseTime();
}


void stopWatch::pauseTime()
{   
    timer->stop();
}

void stopWatch::startTime()
{
    timer->start(100);
}

void stopWatch::updateTime()
{   
    msec+=100;
    if(msec==1000)
    {
        sec+=1;
        msec=0;
    }

    if(sec==60)
    {
        min+=1;
        sec=0;
    }
    showTime();
}

void stopWatch::lapTime()
{ 
  
    view->setGeometry(10,140,210,55);
    resize(220,200);
    view->addItem(time);
    
    view->show();
    resetLapTime();
}
