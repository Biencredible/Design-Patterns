#pragma once
#include "Implementor.h"

class Abstraction
{
protected:
    Implementor* m_pImplementor;


public:
    explicit Abstraction(Implementor* implementor)
        : m_pImplementor(implementor)
    {
    }
    virtual void Operation() = 0;
    virtual ~Abstraction() = default;
};

