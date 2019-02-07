#ifndef OBJETO_H
#define OBJETO_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class QTimer;

class Objeto : public QObject
{
    Q_OBJECT
public:
    explicit Objeto(QObject *parent = nullptr);
    void inicia(int time);

signals:

public slots:
    void onTimeOut(); //Se ha acabado el tiempo de cuenta
private:
    QTimer *m_timer;
};

#endif // OBJETO_H
