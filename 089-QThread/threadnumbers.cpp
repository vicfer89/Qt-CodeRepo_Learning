#include "threadnumbers.h"

ThreadNumbers::ThreadNumbers(QObject *parent)
    : QThread(parent)
{

}

ThreadNumbers::~ThreadNumbers()
{

}

void ThreadNumbers::run()
{
    for(int i = 0; i < 1000000; i++){
        emit newNumber(i);
        msleep(10);
    }
}
