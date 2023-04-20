#pragma once
#include "Component.h"
#include "Decorator.h"

class ConcreteDecoratorA :
    public Decorator
{
    using Decorator::Decorator;
public:

    

    void Operation() override;
};

