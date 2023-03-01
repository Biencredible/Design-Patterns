#include "Client.h"

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
