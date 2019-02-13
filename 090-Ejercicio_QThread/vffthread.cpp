#include "vffthread.h"

VFFThread::VFFThread(int tiempo, QObject *parent)
    : QThread(parent)
{
    mTiempo = tiempo;
    counter = 0;
}

void VFFThread::setCounter(int value)
{
    counter = value;
}

void VFFThread::run()
{
    //int counter = 0;
    while(true)
    {
        if(counter == 100)
        {
            counter = 0;
        }
        emit valueUpdated(counter);
        ++counter;
        msleep(mTiempo);
    }
}
