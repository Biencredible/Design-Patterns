#pragma once
#include <string>

/**
 * The Implementation defines the interface for all implementation classes. It doesn't have to 
 * match the Abstraction's interface. In fact, the two interfaces can be interly different. 
 * Typically the Implementation interface provides only primitive operationsm while the Abstraction
 * defines higher-level operations based on those primitives.
 */
class Implementation
{
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0;
};

