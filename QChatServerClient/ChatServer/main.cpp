#include <QCoreApplication>
#include "messengerserver.h"
#include "messengersocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MessengerServer Server;
    if(!Server.startServer(3333))
    {
        qDebug() << "Error:" << Server.errorString();
        return 1;
    }
    qDebug() << "Server Started...";
    return a.exec();
}
