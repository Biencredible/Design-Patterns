#pragma once
#include "Input.h"
#include "Accelerometer.h"

class AccelAdapter :
    public Input, Accelerometer
{
public:
    bool Up() override;
    bool Down() override;
    bool Left() override;
    bool Right() override;
    std::pair<int, int> Initialize() override;
};

