#pragma once
#include "Component.h"
#include <list>

/**
 * The Composite class represents the complex components that my have children. Usually, the 
 * Composite objects delegate the actual work to their children and then "sum-up" the result.
 */
class Composite :
    public Component
{
    /**
     * @var \SplObjectStorage
     */
protected:
    std::list<Component*> children_;

public:
    /*
     * A composite object can add or remove other components (both simple or complex) to or from 
     * its child list.
     */
    void Add(Component* component) override
    {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    /*
     * Have in mind that this method removes the pointer to the list but doesn't frees the memory,
     * you should do itmanually or better use smart pointers.
     */
    void Remove(Component* component) override
    {
        children_.remove(component);
        component->SetParent(nullptr);
    }

    bool IsComposite() const override
    {
        return true;
    }

    /*
     * The Composite executes its primary logic in a particular way. It traverses recursively 
     * through all its children, collecting and summing their results. Since the composite's 
     * children pass these calls to their children and so forth, the whole object tree is traversed
     * as a result.
     */
    std::string Operation() const override
    {
        std::string result;
        for (const Component* c : children_)
        {
            if (c == children_.back())
            {
                result += c->Operation();
            }
            else
            {
                result += c->Operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }
    
};

