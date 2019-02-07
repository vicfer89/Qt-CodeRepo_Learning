#include "objeto.h"

Objeto::Objeto(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()),this,SLOT(onTimeOut()));
}

void Objeto::inicia(int time)
{
    m_timer->start(time); // 50 ms;
}

void Objeto::onTimeOut()
{
    qDebug() << "El tiempo ha terminado";
}
