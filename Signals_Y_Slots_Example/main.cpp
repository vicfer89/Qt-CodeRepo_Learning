#include <QCoreApplication>
#include "persona.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *p = new QObject;
    Persona *juan = new Persona(p);
    Persona *pedro = new Persona(p);

    juan->set_nombre("Juan");
    pedro->set_nombre("Pedro");

    QObject::connect(juan, SIGNAL(canal(QString)), pedro, SLOT(recibe(QString))); // Conectamos señales
    QObject::connect(pedro, SIGNAL(canal(QString)), juan, SLOT(recibe(QString))); // Conectamos señales

    juan -> transmite("Hola Pedro");
    pedro -> transmite("Hola Juan");


    delete p; // Al ser hijos, al eliminar "p" elimino a "juan" y a "pedro".
    return a.exec();
}
