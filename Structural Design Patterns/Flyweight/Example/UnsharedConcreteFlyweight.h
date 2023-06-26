#pragma once
#include "Flyweight.h"
class UnsharedConcreteFlyweight :
    public Flyweight
{
    int m_InternalState{};


public:
    explicit UnsharedConcreteFlyweight(int internal_state)
        : m_InternalState(internal_state)
    {
    }

    void Operation(int extrinsic) override;
};

