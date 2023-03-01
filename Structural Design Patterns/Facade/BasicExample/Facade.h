#pragma once
#include "A.h"
#include "B.h"
#include "C.h"

class Facade
{  
    A* A_;
    B* B_;
    C* C_;
public:
    Facade();
    ~Facade();
    void Use();
};

