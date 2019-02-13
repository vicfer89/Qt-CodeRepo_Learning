#include "tasknumbers.h"
#include <QDebug>

TaskNumbers::TaskNumbers(char idTask)
{
    mIdTask = idTask;
}

TaskNumbers::~TaskNumbers()
{
    qDebug() << mIdTask << " Ha terminado.";
}

void TaskNumbers::run()
{
    for(int i=0; i <1000; i++){
        qDebug() << mIdTask << ":" << i;
    }
}
