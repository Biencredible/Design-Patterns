#pragma once
#include "Component.h"
class ConcreteComponent :
    public Component
{
public:
    void Operation() override;
};

