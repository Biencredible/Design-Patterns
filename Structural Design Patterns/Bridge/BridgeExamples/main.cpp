#include "ConcreteImplementorA.h"
#include "Abstraction.h"
#include "RefinedAbstraction.h"
#include "ConcreteImplementorB.h"

int main()
{
    ConcreteImplementorB impl;
    Abstraction *p = new RefinedAbstraction{ &impl };
    p->Operation();
}
