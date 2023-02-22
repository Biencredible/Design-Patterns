#include "Adaptee.h"
#include <iostream>

/**
The Adaptee is some useful class (usually 3rd-party or legacy). The client can't use this class directly because it has
an incompatible interface.
*/
void Adaptee::SpecificRequest()
{
    std::cout <<"[Adaptee] SpecificRequest\n";
}
