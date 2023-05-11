#include "Component.h"
#include <iostream>
#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

/**
 * The client code works with all objects using the Component interface. This way it can stay 
 * independent of the concrete classes of components it works with.
*/

void ClientCode(Component* component)
{
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

int main()
{
    /**
     * This way the client code can support both simple components...
    */
    Component* simple = new ConcreteComponent;
    std::cout << "Client: I've got a simple component: \n";
    ClientCode(simple);
    std::cout << "\n\n";
    /**
     * ...as well as decorated ones.
     * 
     * Note how decorators can wrap not only simple components but other decorators as well.
    */
    Component* decorator1 = new ConcreteDecoratorA(simple);
    Component* decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "Client: Now I've got a decoratored component: \n";
    ClientCode(decorator2);
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
