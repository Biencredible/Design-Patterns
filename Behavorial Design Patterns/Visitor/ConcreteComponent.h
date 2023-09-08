#pragma once
#include <string>

#include "Component.h"
#include "Visitor.h"

class ConcreteComponentA :
    public Component
{
public:
    void Accept(Visitor* visitor) const override
    {
        visitor->VisitConcreteComponentA(this);
    }

    std::string ExclusiveMethodOfConcreteComponentA() const
    {
        return "A";
    }
};

class ConcreteComponentB :
    public Component
{
public:
    void Accept(Visitor* visitor) const override
    {
        visitor->VisitConcreteComponentB(this);
    }

    std::string SpecialMethodOfConcreteComponentB() const
    {
        return "B";
    }
};

