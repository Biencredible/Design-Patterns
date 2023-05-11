#pragma once
#include "VisualComponent.h"

class TextView :
    public VisualComponent
{
public:
    std::string draw() override
    {
        return "I draw a TextView object";
    }
};

