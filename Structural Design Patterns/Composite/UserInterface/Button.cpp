#include "Button.h"
#include <iostream>

void Button::Paint()
{
    if(m_IsVisible)
    {
        std::cout << "[Button] Painting...\n";
    }
}

void Button::SetVisibility(bool visibility)
{
    std::cout << std::boolalpha;
    std::cout << "[Button] Visibility: " << visibility << std::endl;
    m_IsVisible = visibility;
}

void Button::Add(Widget* pWidget)
{
    throw std::runtime_error{ "Not implemented" };
}

void Button::Remove(Widget* pWidget)
{
    throw std::runtime_error{ "Not implemented" };
}
