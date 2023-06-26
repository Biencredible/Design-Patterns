#include "UnsharedConcreteFlyweight.h"
#include <iostream>

void UnsharedConcreteFlyweight::Operation(int extrinsic)
{
    std::cout << "Internal state:" << m_InternalState << std::endl;
    std::cout << "Extrinsic state:" << extrinsic << std::endl;
}
