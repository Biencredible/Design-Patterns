#pragma once
#include "Subject.h"

class RealSubject;

class Proxy :
    public Subject
{
    RealSubject* m_pSubject{};
public:
    void Request() override;

    ~Proxy();
};

