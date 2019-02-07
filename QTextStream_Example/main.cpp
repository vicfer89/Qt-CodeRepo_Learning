#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream IOData;
    QString Contenido;
    QFile Fichero;

    Fichero.setFileName("C:/Users/VFF/Desktop/Documento_Text_Qt.txt");
    Fichero.open(QIODevice::ReadWrite | QIODevice::Text);
    if(!Fichero.isOpen())
    {
        qDebug() << "Error: Fichero no abierto";
        return a.exec();
    }
    IOData.setDevice(&Fichero);
    //IOData << "texto de prueba";
    Contenido = IOData.readAll();
    qDebug() << Contenido;
    Fichero.flush();
    Fichero.close();

    return a.exec();
}
