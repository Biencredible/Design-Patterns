#pragma once
#include "Adaptee.h"
#include "Target.h"

class AdapterComposition : public Target
{
    Adaptee* adaptee;
public:
    void Request() override;
};
