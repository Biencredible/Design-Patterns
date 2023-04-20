#include "ConcreteDecoratorA.h"
#include <iostream>

void ConcreteDecoratorA::Operation()
{
    std::cout << "[ConcreteDecoratorA] Operation invoked\n";
    Decorator::Operation();
}
