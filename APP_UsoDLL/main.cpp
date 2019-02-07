#include <QCoreApplication>
#include "mydll_example.h"
#include "mystaticlib_example.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyDLL_Example mDLL;
    MyStaticLib_Example mSTAT;
    mDLL.saluda();
    mSTAT.salida();

    return a.exec();
}
