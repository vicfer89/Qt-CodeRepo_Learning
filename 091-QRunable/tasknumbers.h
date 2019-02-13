#ifndef TASKNUMBERS_H
#define TASKNUMBERS_H

#include <QRunnable>

class TaskNumbers : public QRunnable
{
public:
    TaskNumbers(char idTask);
    ~TaskNumbers();
protected:
    void run() override;
private:
    char mIdTask;
};

#endif // TASKNUMBERS_H
