#pragma once
#include "Subject.h"
#include "RealSubject.h"

/**
 * The Proxy has an interface identical to the RealSubject.
*/
class Proxy : public Subject
{
    // @var RealSubject
private:
    RealSubject *real_subject_;
    bool checkAccess() const
    {
        // Some real checks should go here.
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }

    void logAccess() const
    {
        std::cout << "Proxy: Logging the time of request.\n";
    }

    /**
     * The Proxy maintains a reference to an object of the RealSubject class. It can be either 
     * lazy-loaded or passed to the Proxy by the client.
    */
public:
    Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject_))
    {}

    ~Proxy()
    {
        delete real_subject_;
    }

    /**
     * The most common applications of the Proxy pattern are lazy loading, caching, controlling the
     * access, logging, etc. A Proxy can perform one of these things and then, depending on the 
     * result, pass the execution to the same method in alinked RealSubject.
    */
    void Request() const override
    {
        if (this->checkAccess())
        {
            this->real_subject_->Request();
            this->logAccess();
        }
    }
};