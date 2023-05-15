#include "Composite.h"
#include <iostream>

int depth{};
void Composite::Operation()
{
    ++depth;
    std::cout << "[Composite] Operation \n";
    for(auto pChild : m_Children)
    {
        for(int i = 0; i < depth; ++i)
        {
            std::cout << '/t';
        }
        std::cout << "|-";
        pChild->Operation();
    }
    --depth;
}

void Composite::Add(Component* pComponent)
{
    m_Children.push_back(pComponent);
}

void Composite::Remove(Component* pComponent)
{
    auto newend = remove(begin(m_Children), end(m_Children), pComponent); // Only works since C++20
    m_Children.erase(newend, end(m_Children));
}

Component* Composite::GetChild(int index)
{
    return m_Children[index];
}
