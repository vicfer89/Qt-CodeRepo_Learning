#include "DuService.h"
#include <QTextStream>
#include <QDebug>
#include <QFile>

DuService::DuService(int argc, char **argv)
    : QtService<QCoreApplication>(argc,argv,"MiServicio")
{
    // establece la información del servicio
    setServiceDescription("Este es el servicio de DuarteCorporation");
    setServiceFlags(QtServiceBase::CanBeSuspended);
}

DuService::~DuService()
{
}

void DuService::start()
{
    QCoreApplication *app = application();
    qDebug() << "Servicio iniciado en: " << app->applicationDirPath();
    log("./iniciado.txt", "Servicio iniciado correctamente");
}

void DuService::pause()
{
    qDebug() << "Servicio pausado";
    log("./pausado.txt", "Servicio pausado correctamente");
}

void DuService::resume()
{
    qDebug() << "Servicio reactivado";
    log("./reactivado.txt", "Servicio reactivado correctamente");
}

void DuService::stop()
{
    qDebug() << "Servicio detenido";
    log("./detenido.txt", "Servicio detenido correctamente");
}

void DuService::log(const QString &filename, const QString &message) const
{
    // salida por archivo
    QFile archivo(filename);
    archivo.open(QFile::WriteOnly);
    QTextStream txtstr(&archivo);
    txtstr << message;
    archivo.flush();
    archivo.close();
}
