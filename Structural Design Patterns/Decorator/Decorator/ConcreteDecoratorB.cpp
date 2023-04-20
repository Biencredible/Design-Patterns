#include "ConcreteDecoratorB.h"
#include <iostream>

void ConcreteDecoratorB::Operation()
{
    std::cout << "[ConcreteDecoratorB Operation invoked\n";
    Decorator::Operation();
}

void ConcreteDecoratorB::OtherOperation()
{
    std::cout << "Supporting Operation\n";
}
