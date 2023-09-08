#pragma once
#include <iostream>

class AbstractClass
{
public:
    void TemplateMethod() const
    {
        this->BaseOperation1();
        this->RequiredOperations1();
        this->BaseOperation2();
        this->Hook1();
        this->RequiredOperations2();
        this->BaseOperation3();
        this->Hook2();
    }

protected:
    // These operations already have an implementation
    void BaseOperation1() const
    {
        std::cout << "AbstractClass says: I am doing the bulk of the work.\n";
    }

    void BaseOperation2() const
    {
        std::cout << "AbstractClass says: But I let subclasses override some operations.\n";
    }

    void BaseOperation3() const
    {
        std::cout << "AbstractClass says: But I am doing the bulk of the work anyway.\n";
    }

    // These operations have to be implemented in subclasses.
    virtual void RequiredOperations1() const = 0;
    virtual void RequiredOperations2() const = 0;

    // Hooks can be overridden by subclasses or can be left empty.
    virtual void Hook1() const {}
    virtual void Hook2() const {}
};

