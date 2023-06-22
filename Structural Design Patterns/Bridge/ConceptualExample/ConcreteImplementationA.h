#pragma once
#include "Implementation.h"

/**
 * Each concrete Implementation corresponds to a specific platform and implements the 
 * Implementation interface using that platform's API.
*/
class ConcreteImplementationA :
    public Implementation
{
public:
    std::string OperationImplementation() const override
    {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};

