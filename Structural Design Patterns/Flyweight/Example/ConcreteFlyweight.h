#pragma once
#include "Flyweight.h"
class ConcreteFlyweight :
    public Flyweight
{
    int* m_pIntrinsicState{};

public:


    explicit ConcreteFlyweight(int* p_intrinsic_state)
        : m_pIntrinsicState(p_intrinsic_state)
    {
    }


    void Operation(int extrinsic) override;
};

