#pragma once
#include "Implementation.h"

/**
 * The ABstraction defines the interface for "control" part of the two class hierarchies. It 
 * maintains a reference to an object of the implementation hierarchy and delegates all of the 
 * real work to this object.
*/
class Abstraction
{
protected:
    Implementation* implementation_;

public:

    explicit Abstraction(Implementation* implementation)
        : implementation_(implementation)
    {
    }

    virtual ~Abstraction() {}

    virtual std::string Operation() const
    {
        return "Abstraction: Base operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

