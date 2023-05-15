#include "Leaf.h"
#include <iostream>

void Leaf::Operation()
{
    std::cout << "[Leaf] Operation invoked \n";
}

void Leaf::Add(Component* pComponent)
{
}

void Leaf::Remove(Component* pComponent)
{
}

Component* Leaf::GetChild(int index)
{
    return nullptr;
}
