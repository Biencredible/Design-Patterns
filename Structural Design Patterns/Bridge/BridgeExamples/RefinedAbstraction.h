#pragma once
#include "Abstraction.h"
class RefinedAbstraction :
    public Abstraction
{
    using Abstraction::Abstraction;
public:
    void Operation() override;
};

