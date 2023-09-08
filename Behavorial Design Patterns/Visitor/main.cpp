#include <array>
#include <iostream>

#include "Component.h"
#include "ConcreteVisitor.h"
#include "Visitor.h"

void ClientCode(std::array<const Component*, 2> components, Visitor* visitor)
{
    for(const Component* component: components)
    {
        component->Accept(visitor);
    }
}

int main()
{
    std::array<const Component *, 2> components = {new ConcreteComponentA(), new ConcreteComponentB()};
    std::cout << "The client code works with all visitors via the base Visitor interface:\n";
    ConcreteVisitor1 *visitor1 = new ConcreteVisitor1;
    ClientCode(components, visitor1);
    std::cout << "\n";
    std::cout << "It allows the same client code to work with different types of visitors:\n";
    ConcreteVisitor2 *visitor2 = new ConcreteVisitor2;
    ClientCode(components, visitor2);

    for (const Component *comp : components) {
        delete comp;
    }
    delete visitor1;
    delete visitor2;

    return 0;
}
