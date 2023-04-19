#include "ConcreteDecoratorB.h"
#include <iostream>

void ConcreteDecoratorB::Operation()
{
    std::cout << "[ConcreteDecoratorB Operation invoked\n";
    m_ptr->Operation();
}
