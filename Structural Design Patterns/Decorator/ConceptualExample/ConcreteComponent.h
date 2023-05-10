#pragma once
#include "Component.h"

/**
 * Concrete Components provide default implementations of the operations. There might be several
 * variations of these classes.
*/
class ConcreteComponent : public Component
{
public:
    std::string Operation() const override
    {
        return "ConcreteComponent";
    }
};

