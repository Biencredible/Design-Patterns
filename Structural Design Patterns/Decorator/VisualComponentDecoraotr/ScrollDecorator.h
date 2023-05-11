#pragma once
#include "Decorator.h"
class ScrollDecorator :
    public Decorator
{
public:

    explicit ScrollDecorator(VisualComponent* visualComponent)
        : Decorator(visualComponent)
    {
    }

    std::string draw() override
    {
        return (Decorator::draw() + " and add a scroll bar \n");
    }

    std::string scroll()
    {
        return "I can scroll up and down";
    }

};

