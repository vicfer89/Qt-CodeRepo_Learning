#include <QCoreApplication>
#include <QPointer>
#include <QDebug>

class persona : public QObject
{
public:
    persona(const QString &nombre, QObject *padre = nullptr) : QObject(padre)
    {
        m_nombre = nombre;
    }

    QString nombre() const
    {
        return m_nombre;
    }

private:
    QString m_nombre;
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QPointer<persona> ptr_persona= new persona("Victor");

    qDebug() << ptr_persona->nombre();

    delete ptr_persona;

    return a.exec();
}

