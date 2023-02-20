#pragma once
#include "Input.h"
#include <random>
class Keyboard : public Input
{
    std::default_random_engine m_Engine{12345};
    bool SimulateInput();
public:
    bool Up() override;
    bool Down() override;
    bool Left() override;
    bool Right() override;

};