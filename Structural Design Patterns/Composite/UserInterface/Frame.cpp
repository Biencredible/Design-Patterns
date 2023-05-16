#include "Frame.h"
#include <iostream>

int depth{};
void Frame::Paint()
{
    if (!m_IsVisible) return;

    std::cout << "[Frame] Painting...\n";
    ++depth;
    for(auto pChild: m_Children)
    {
        for(int i = 0; i < depth; ++i)
        {
            std::cout << '\t';
        }
        pChild->Paint();
    }
    --depth;
}

void Frame::SetVisibility(bool visibility)
{
    ++depth;
    m_IsVisible = visibility;
    std::cout << "[Frame] Changing Visibility\n";
    for(auto pChild : m_Children)
    {
        for(int i = 0; i < depth; ++i)
        {
            std::cout << '\t';
        }
        pChild->SetVisibility(visibility);
    }
}

void Frame::Add(Widget* pWidget)
{
    m_Children.push_back(pWidget);
}

void Frame::Remove(Widget* pWidget)
{
    m_Children.erase(remove(begin(m_Children), end(m_Children), pWidget), end(m_Children)); // Only works since C++20
}
