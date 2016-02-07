#include "stopwatch.h"
//#include "ui_stopwatch.h"

#include <QTimer>

stopWatch::stopWatch(QWidget *parent) :
    QLCDNumber(parent)
{   
    startAction->setText("Start");
    pauseAction->setText("Pause");
    resetAction->setText("Reset");
    
    bar->addAction(startAction);
    bar->addAction(pauseAction);
    bar->addAction(resetAction);
    
    resize(180,150);
}

stopWatch::~stopWatch()
{
  
}
