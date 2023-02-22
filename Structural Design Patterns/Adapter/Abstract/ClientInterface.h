#pragma once

/**
The Client interface describes a protocol that other classes must follow to be able to collaborate with the client code.
*/
class ClientInterface
{
public:
    virtual void Request() = 0;
    virtual ~ClientInterface() = default;
};