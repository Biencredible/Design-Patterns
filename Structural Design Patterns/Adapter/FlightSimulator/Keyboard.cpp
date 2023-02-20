#include "Keyboard.h"

bool Keyboard::SimulateInput()
{
    std::bernoulli_distribution dist{.5};
    return dist(m_Engine);
}

bool Keyboard::Up()
{
    return SimulateInput();
}

bool Keyboard::Down()
{
    return SimulateInput();
}

bool Keyboard::Left()
{
    return SimulateInput();
}

bool Keyboard::Right()
{
    return SimulateInput();
}