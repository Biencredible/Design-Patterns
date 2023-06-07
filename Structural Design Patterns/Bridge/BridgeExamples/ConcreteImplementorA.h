#pragma once
#include "Implementor.h"
class ConcreteImplementorA :
    public Implementor
{
public:
    void OperationImpl() override;
};

