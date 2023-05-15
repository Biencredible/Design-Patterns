#pragma once
class Component
{
public:
    virtual void Operation() = 0;
    virtual void Add(Component* pComponent) = 0;
    virtual void Remove(Component* pComponent) = 0;
    virtual Component* GetChild(int index) = 0;
    virtual ~Component() = default;
};

