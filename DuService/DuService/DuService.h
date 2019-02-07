#ifndef MYSERVICE_H
#define MYSERVICE_H

#include <QCoreApplication>
#include "qtservice.h"

class DuService : public QtService<QCoreApplication>
{
public:
    DuService(int argc, char **argv);
    ~DuService();
    void start();  // inicia el servicio
    void pause();  // pausa el servicio
    void resume(); // continuar la ejecución del servicio
    void stop();   // detiene el servicio
private:
    void log(const QString &filename, const QString &message) const;
};

#endif // MYSERVICE_H
