#pragma once
#include "Component.h"
#include <vector>

class Composite :
    public Component
{
    std::vector<Component*> m_Children;
public:
    void Operation() override;
    void Add(Component* pComponent) override;
    void Remove(Component* pComponent) override;
    Component* GetChild(int index) override;
};

