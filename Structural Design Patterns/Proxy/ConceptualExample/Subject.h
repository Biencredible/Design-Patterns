#pragma once
/*
 *The SUbject interface declares common operations for both the RealSubject and the Proxy. As long 
 *as the client works with RealSubject using this interface, you'll be able to pass it a proxy 
 *instead of a real subject.
 */
class Subject
{
public:
    virtual void Request() const = 0;
};

