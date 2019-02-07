#ifndef OBJETO_H
#define OBJETO_H

#include <QObject>
#include <QDebug>

class objeto : public QObject
{
    Q_OBJECT
public:
    explicit objeto(QObject *parent = nullptr);
    ~objeto();
    void sendSignals();

signals:
    void signal();
    void signal(int);
    void signal(char);

public slots:
    void onSignal();
    void onSignal(int);
    void onSignal(char);
};

#endif // OBJETO_H
