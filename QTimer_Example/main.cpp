#include <QCoreApplication>
#include "objeto.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Objeto obj;
    obj.inicia(1000);

    return a.exec();
}
