#pragma once
#include "Subject.h"
#include <iostream>

/**
 * The RealSubject contains some core business logic. Usually, RealSubjects are capable of doing 
 * some usefull work which may also be very slow or sensitive - e.g. correcting input data. A 
 * Proxy can solve these issues without any changes to the RealSubject's code.
*/
class RealSubject : public Subject
{
public:
    void Request() const override
    {
        std::cout << "RealSubject: Handling request.\n";
    }
};