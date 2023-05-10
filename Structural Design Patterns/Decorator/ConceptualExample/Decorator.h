#pragma once
#include "Component.h"
/**
 * The base Decorator class follows the same interface as the other components. The primary purpose
 * of this class is to define the wrapping interface for all concrete decorators. The default 
 * implementation of the wrapping cpde might onclude a field for storing a wrapped component and 
 * the means to initialize it.
 */
class Decorator :
    public Component
{
protected:
    Component* component_;
public:

    explicit Decorator(Component* component)
        : component_(component)
    {
    }

    /**
     * The Decorator delegates all work to the wrapped component.
    */
    std::string Operation() const override
    {
        return this->component_->Operation();
    }
};

