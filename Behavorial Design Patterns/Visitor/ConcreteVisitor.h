#pragma once
#include <iostream>

#include "ConcreteComponent.h"
#include "Visitor.h"
class ConcreteVisitor1 :
    public Visitor
{
public:
    void VisitConcreteComponentA(const ConcreteComponentA* element) const override
    {
        std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
    }

    void VisitConcreteComponentB(const ConcreteComponentB *element) const override
    {
        std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1\n";
    }

};

class ConcreteVisitor2 :
    public Visitor
{
public:
    void VisitConcreteComponentA(const ConcreteComponentA *element) const override
    {
        std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
    }

    void VisitConcreteComponentB(const ConcreteComponentB *element) const override
    {
        std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
    }
};

