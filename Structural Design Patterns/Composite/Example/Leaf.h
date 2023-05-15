#pragma once
#include "Component.h"
class Leaf :
    public Component
{
public:
    void Operation() override;
    void Add(Component* pComponent) override;
    void Remove(Component* pComponent) override;
    Component* GetChild(int index) override;
};

