#include <QCoreApplication>
#include <QThreadPool>
#include "tasknumbers.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TaskNumbers *T = new TaskNumbers('x');
    TaskNumbers *Y = new TaskNumbers('y');
    QThreadPool::globalInstance()->start(T,QThread::LowPriority);
    QThreadPool::globalInstance()->start(Y,QThread::LowestPriority);

    return a.exec();
}
