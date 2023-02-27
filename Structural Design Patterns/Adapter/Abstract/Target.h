#pragma once

/**
The Client interface describes a protocol that other classes must follow to be able to collaborate with the client code.
*/
class Target
{
public:
    virtual void Request() = 0;
    virtual ~Target() = default;
};