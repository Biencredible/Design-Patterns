#include "AdapterComposition.h"
#include <iostream>

void AdapterComposition::Request()
{
    std::cout << "[AdapterComposition] Calling SpecificRequest\n";
    adaptee->SpecificRequest();
}
