#pragma once
#include <string>

class VisualComponent
{
public:
    virtual ~VisualComponent() {}
    virtual std::string  draw() = 0;
};

