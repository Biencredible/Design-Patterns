#pragma once
#include "AbstractClass.h"

class ConcreteClass1 :
    public AbstractClass
{
protected:
    void RequiredOperations1() const override
    {
        std::cout << "ConcreteClass2 says: Implemented Operation1\n";
    }

    void RequiredOperations2() const override
    {
        std::cout << "ConcreteClass1 says: Implemented Operation2\n";
    }
};

class ConcreteClass2 :
    public AbstractClass
{
protected:
    void RequiredOperations1() const override
    {
        std::cout << "ConcreteClass2 says: Implemented Operation1\n";
    }

    void RequiredOperations2() const override
    {
        std::cout << "ConcreteClass2 says: Implemented Operation2\n";
    }

    void Hook1() const override
    {
        std::cout << "ConcreteClass2 says: Overridden Hook1\n";
    }
};

