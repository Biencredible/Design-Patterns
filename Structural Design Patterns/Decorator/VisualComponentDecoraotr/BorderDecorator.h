#pragma once
#include "Decorator.h"
class BorderDecorator :
    public Decorator
{
public:


    explicit BorderDecorator(VisualComponent* visualComponent)
        : Decorator(visualComponent)
    {
    }

    std::string draw() override
    {
        return Decorator::draw() + " and add a border \n";
    }
};

