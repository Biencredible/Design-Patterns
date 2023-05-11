#pragma once
#include "VisualComponent.h"
class Decorator :
    public VisualComponent
{
protected:
    VisualComponent* visualComponent_;
public:

    Decorator(VisualComponent* visualComponent) : 
        visualComponent_(visualComponent)
    {
    }


    std::string draw() override
    {
        return visualComponent_->draw();
    }
};

