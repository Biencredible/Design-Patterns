#pragma once
#include "Adaptee.h"
#include "Target.h"

class AdapterInheritance : public Target, public Adaptee
{
public:
    void Request() override;
};
