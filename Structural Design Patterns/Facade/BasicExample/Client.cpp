#include "Client.h"

/*
The client uses the facade instead of calling the subsystem objects directly.
*/
Client::Client()
{
    facade = new Facade(); 
}

Client::~Client()
{
    delete facade;   
}

void Client::invoke()
{
    facade->Use(); 
}
