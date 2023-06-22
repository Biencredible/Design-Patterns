#pragma once
#include "Abstraction.h"

/**
 * You can extend Abstraction without changing the Implementation classes.
*/
class ExtendedAbstraction :
    public Abstraction
{
public:

    explicit ExtendedAbstraction(Implementation* implementation)
        : Abstraction(implementation)
    {
    }

    std::string Operation() const override
    {
        return "ExtendedAbstraction: Extended operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

