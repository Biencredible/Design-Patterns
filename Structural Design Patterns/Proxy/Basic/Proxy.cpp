#include "Proxy.h"
#include "RealSubject.h"
#include <iostream>

void Proxy::Request()
{
    if(m_pSubject == nullptr)
    {
        std::cout << "[Proxy] Creating RealSubject\n";
        m_pSubject = new RealSubject{};
    }
    std::cout << "[Proxy] Additional behavior\n\n";
    m_pSubject->Request();
}

Proxy::~Proxy()
{
    delete m_pSubject;
}
