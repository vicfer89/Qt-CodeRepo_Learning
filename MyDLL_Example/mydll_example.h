#ifndef MYDLL_EXAMPLE_H
#define MYDLL_EXAMPLE_H

#include "mydll_example_global.h"
#include <QDebug>

class MYDLL_EXAMPLESHARED_EXPORT MyDLL_Example
{

public:
    MyDLL_Example();
    void saluda() const;
};

#endif // MYDLL_EXAMPLE_H
