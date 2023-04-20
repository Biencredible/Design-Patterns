#pragma once
#include "Component.h"
class Decorator :
    public Component
{
    Component *m_ptr{};

public:

    explicit Decorator(Component* component)
        : m_ptr(component)
    {
    }

    void Operation() override;
};

