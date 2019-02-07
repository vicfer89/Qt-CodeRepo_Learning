#include "mystaticlib_example.h"

MyStaticLib_Example::MyStaticLib_Example()
{
}

void MyStaticLib_Example::salida() const
{
    qDebug() << "Hola desde librería estática";
}
