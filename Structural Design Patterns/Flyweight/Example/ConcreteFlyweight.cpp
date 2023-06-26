#include "ConcreteFlyweight.h"
#include <iostream>

void ConcreteFlyweight::Operation(int extrinsic)
{
    std::cout << "Intrinsic state:" << *m_pIntrinsicState << std::endl;
    std::cout << "Extrinsic state:" << extrinsic << std::endl;
}
