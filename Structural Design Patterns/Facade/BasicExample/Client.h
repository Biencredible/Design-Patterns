#pragma once
#include "Facade.h"


class Client
{
    Facade* facade;

public:
    Client();
    ~Client();
    void invoke();
};

