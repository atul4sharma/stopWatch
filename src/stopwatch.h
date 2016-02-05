#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QLCDNumber>

namespace Ui {
class stopWatch;
}

class stopWatch : public QLCDNumber
{
    Q_OBJECT

public:
    explicit stopWatch(QWidget *parent = 0);
    ~stopWatch();
};

#endif // STOPWATCH_H
