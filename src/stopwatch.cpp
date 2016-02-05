#include "stopwatch.h"
//#include "ui_stopwatch.h"

#include <QTimer>

stopWatch::stopWatch(QWidget *parent) :
    QLCDNumber(parent)
{   
        QTimer *timer=new QTimer(this);        
        resize(200,150);
    
}

stopWatch::~stopWatch()
{
  
}
