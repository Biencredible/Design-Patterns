#pragma once
#include "Input.h"
#include "Accelerometer.h"

class AccelAdapter :
    public Input
{
    Accelerometer accel;
public:
    bool Up() override;
    bool Down() override;
    bool Left() override;
    bool Right() override;
};

