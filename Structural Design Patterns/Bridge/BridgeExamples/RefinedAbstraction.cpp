#include "RefinedAbstraction.h"
#include <iostream>

void RefinedAbstraction::Operation()
{
    std::cout << "[RefinedAbstraction] =>";
    m_pImplementor->OperationImpl();
}
