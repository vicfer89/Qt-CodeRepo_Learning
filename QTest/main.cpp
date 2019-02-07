#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QDir>

static QDir Directorio;
static uint Accu = 0;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QString Folder = "C:/Qt/";
    Directorio.setPath(Folder);
    qDebug().noquote() << "Seleccionada carpeta:" << Folder;

    for(uint i = 0; i < Directorio.count() ; i++)
    {
        qDebug().noquote().nospace() << "Fichero: "
                                     << Folder << Directorio[i]
                                     << '\t'
                                     << "Caracteres: " << Directorio[i].size() + Folder.size() ;
        Accu += Directorio[i].size();
    }

    qDebug().noquote() << "Tamaño acumulado:" << Accu;

    return a.exec();
}
