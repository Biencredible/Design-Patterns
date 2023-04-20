#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

void Operate(Component *c)
{
    c->Operation();
}

int main()
{
    ConcreteComponent component{};
    ConcreteDecoratorA decA{ &component };
    //decA.Operation();
    ConcreteDecoratorB decB{ &decA };
    //decB.Operation();
    //decB.OtherOperation();
    Operate(&decB);
}
