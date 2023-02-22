#pragma once
#include "Adaptee.h"
#include "ClientInterface.h"

/**
The Adapter is aclass that's able to work with both the client and the Adaptee: it implements the client interface, 
while wrapping the service object. THe adapter receives calls from the client via the adapter interface and translates 
calls to the wrapped service object in a format it can understand.
*/
class AdapterInheritance : public ClientInterface, public Adaptee
{
public:
    void Request() override;
};
