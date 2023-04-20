#pragma once
#include "Component.h"
#include "Decorator.h"

class ConcreteDecoratorB :
    public Decorator
{

    using Decorator::Decorator;

public:
    

    void Operation() override;
    void OtherOperation();
};

