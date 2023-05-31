#pragma once
#include "Component.h"
/*
 * The Leaf class represents the end object of a composition. A leaf can't have any children.
 * 
 * Usually, it's the Leaf objects that do the actual work, whereas Composite objects only delegate 
 * to their sub-components.
 */
class Leaf :
    public Component
{
public:
    std::string Operation() const override
    {
        return "Leaf";
    }
};

