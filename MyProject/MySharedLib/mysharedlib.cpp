#include "mysharedlib.h"
#include <QDebug>

MySharedLib::MySharedLib()
{
}

void MySharedLib::sayHelloWorld() const
{
    qDebug() << "Hola Mundo DLL";
}
