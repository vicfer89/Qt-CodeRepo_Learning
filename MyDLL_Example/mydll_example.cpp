#include "mydll_example.h"

MyDLL_Example::MyDLL_Example()
{
}

void MyDLL_Example::saluda() const
{
    qDebug() << "Hola desde una libreria DLL";
}
