#pragma once
#include "Flyweight.h"
#include <unordered_map>

class FlyweightFactory
{
    inline static std::unordered_map<int, Flyweight*> m_Flyweights{};
public:
    Flyweight* GetFlyweight(int key);
    Flyweight* GetUnsharedFlyweight(int value);
};

