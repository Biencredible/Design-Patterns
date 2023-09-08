#pragma once
class ConcreteComponentB;
class ConcreteComponentA;

class Visitor
{
public:
    virtual void VisitConcreteComponentA(const ConcreteComponentA *element) const = 0;
    virtual void VisitConcreteComponentB(const ConcreteComponentB *element) const = 0;
};

