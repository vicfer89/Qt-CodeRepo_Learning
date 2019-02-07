#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

static QTextStream io;
static QFile arch;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString Contenido;

    arch.setFileName(":/main.cpp"); //Entra al .qrc con ":"
    arch.open(QIODevice::Text | QIODevice::ReadOnly);
    io.setDevice(&arch);
    Contenido = io.readAll();
    arch.close();
    qDebug() << Contenido;

    return a.exec();
}
