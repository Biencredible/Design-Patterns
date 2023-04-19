#pragma once
#include "Component.h"
class ConcreteDecoratorB :
    public Component
{
    Component* m_ptr{};

public:
    explicit ConcreteDecoratorB(Component* component)
        : m_ptr(component)
    {
    }

    void Operation() override;
};

