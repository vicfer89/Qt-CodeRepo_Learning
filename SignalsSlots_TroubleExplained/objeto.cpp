#include "objeto.h"

objeto::objeto(QObject *parent) : QObject(parent)
{
    /*connect(this, SIGNAL(signal()), this, SLOT(onSignal()));
    connect(this, SIGNAL(signal(int)), this, SLOT(onSignal(int)));
    connect(this, SIGNAL(signal(char)), this, SLOT(onSignal(char)));*/
    //Forma alternativa: requiere QMAKE_CXXFLAGS += -std=gnu++11
    auto signal1 = static_cast<void (objeto::*)(void)>(onSignal);
    auto slot1 = static_cast<void (objeto::*)(void)>(onSignal);
    //auto signal2 = static_cast<void (objeto::*)(int)>(onSignal(int));
    //auto signal2 = static_cast<void (objeto::*)(char)>(onSignal(char));

    connect(this, signal1, this, slot1);
    //connect(this, &objeto::signal, this, onSignal);
    //connect(this, &objeto::signal, this, onSignal);
}

objeto::~objeto()
{

}

void objeto::sendSignals()
{
    emit signal();
    //emit signal(5);
    //emit signal('q');
}

void objeto::onSignal()
{
    qDebug() << "Slot onSignal()";
}

void objeto::onSignal(int e)
{
    qDebug() << "Slot onSignal(int)" << e;
}

void objeto::onSignal(char c)
{
    qDebug() << "Slot onSignal(char)" << c;
}
