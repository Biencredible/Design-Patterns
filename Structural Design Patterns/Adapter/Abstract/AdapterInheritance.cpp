#include "AdapterInheritance.h"
#include <iostream>

void AdapterInheritance::Request()
{
    std::cout << "[AdapterComposition] Calling SpecificRequest\n";
    SpecificRequest();
}
