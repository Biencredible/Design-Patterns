#pragma once
#include "Component.h"
class ConcreteDecoratorA :
    public Component
{
    Component *m_ptr{};
public:

    explicit ConcreteDecoratorA(Component* component)
        : m_ptr(component)
    {
    }

    void Operation() override;
};

