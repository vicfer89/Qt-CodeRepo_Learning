#include "persona.h"

Persona::Persona(QObject *parent) : QObject(parent)
{

}

void Persona::recibe(const QString &palabras)
{
    qDebug() << m_nombre << "Ha recibido: " << palabras;
}

void Persona::transmite(const QString &palabras)
{
    emit canal(palabras);
}

void Persona::set_nombre(const QString &nombre)
{
    m_nombre = nombre;
}
