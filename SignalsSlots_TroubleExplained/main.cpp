#include <QCoreApplication>
#include "objeto.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    objeto o;
    o.sendSignals();

    return a.exec();
}
