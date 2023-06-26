#include "FlyweightFactory.h"
#include "UnsharedConcreteFlyweight.h"
#include "ConcreteFlyweight.h"

Flyweight* FlyweightFactory::GetFlyweight(int key)
{
    auto found = m_Flyweights.find(key) != end(m_Flyweights);
    if(found)
    {
        return m_Flyweights[key];
    }
    static int intrinsicState{ 100 };
    Flyweight* p = new ConcreteFlyweight{ &intrinsicState };
    m_Flyweights[key] = p;
    return p;
}

Flyweight* FlyweightFactory::GetUnsharedFlyweight(int value)
{
    return new UnsharedConcreteFlyweight{ value };
}
