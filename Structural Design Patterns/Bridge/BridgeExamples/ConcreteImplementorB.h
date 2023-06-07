#pragma once
#include "Implementor.h"
class ConcreteImplementorB :
    public Implementor
{
public:
    void OperationImpl() override;
};

