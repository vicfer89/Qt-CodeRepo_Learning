#include "myservice.h"

MyService::MyService(int argc, char **argv) : QtService<QCoreApplication>(argc,argv,"MyService")
{
    try
    {
        //Set the service information
        setServiceDescription("This is my service.");
        setServiceFlags(QtServiceBase::CanBeSuspended);
    }
    catch(...)
    {
        qCritical() << "An unknown error in the constructor";
    }
}

MyService::~MyService()
{
    try
    {
        //TO DO - release any memory
    }
    catch(...)
    {
        qCritical() << "An unknown error in the deconstructor";
    }
}

void MyService::start()
{
    try
    {
        QCoreApplication *app = application();
        qDebug() << "Service started!";
        qDebug() << app->applicationDirPath();
        //MyClass.dosomething();
    }
    catch(...)
    {
        qCritical() << "An unknown error in the start";
    }
}

void MyService::pause()
{
    try
    {
        qDebug() << "Service paused!";
    }
    catch(...)
    {
        qCritical() << "An unknown error in the pause";
    }
}

void MyService::resume()
{
    try
    {
        qDebug() << "Service resumed!";
    }
    catch(...)
    {
        qCritical() << "An unknown error in the resume";
    }
}

void MyService::stop()
{
    try
    {
        qDebug() << "Service stopped!";
    }
    catch(...)
    {
        qCritical() << "An unknown error in the stop";
    }
}
