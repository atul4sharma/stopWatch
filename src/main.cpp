#include "stopwatch.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    stopWatch w;
    w.show();

    return app.exec();
}

