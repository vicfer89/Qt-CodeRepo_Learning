#ifndef MYSHAREDLIB_H
#define MYSHAREDLIB_H

#include "mysharedlib_global.h"

class MYSHAREDLIBSHARED_EXPORT MySharedLib
{

public:
    MySharedLib();
    void sayHelloWorld() const;
};

#endif // MYSHAREDLIB_H
