/*
Convert the interface of a class into another interface clients expect. Adapter lets class work together that couldn't
otherwise because of incompatible interfaces.

Implement through Composition or Inheritance
Composition:
Adapter composes adaptee and calls its method through a reference/pointer

Inerhitance:
Adapter inherits from the adaptee and calls the methods directly
*/

// Example
#include <iostream>
//Target.h
class Target
{
public:
    virtual void Request() = 0;
    virtual ~Target() = default;
};

//Client.cpp
//#include "Target.h"
void Client(Target* pTarget)
{
    pTarget->Request();
}

//Adaptee.h
class Adaptee
{
public:
    void SpecificRequest();
};

//Adaptee.cpp
void Adaptee::SpecificRequest()
{
    std::cout <<"[Adaptee] SpecificRequest\n";
}

//AdapterComposition.h
class AdapterComposition : public Target
{
    Adaptee* adaptee;
public:
    void Request() override;
};

//AdapterComposition.cpp
void AdapterComposition::Request()
{
    std::cout << "[AdapterComposition] Calling SpecificRequest\n";
    adaptee->SpecificRequest();
}

//AdapterInheritance.h
class AdapterInheritance : public Target, public Adaptee
{
public:
    void Request() override;
};

void AdapterInheritance::Request()
{
    std::cout << "[AdapterComposition] Calling SpecificRequest\n";
    SpecificRequest();
}

int main() 
{
    AdapterComposition a;
    Client(&a);

    AdapterInheritance b;
    Client(&b);
}



