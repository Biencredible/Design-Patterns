#pragma once
#include <random>

class Accelerometer
{
    std::default_random_engine m_Engine{12345};
    public: 
    double GetHorizontalAxis();
    double GetVerticalAxis();

};
