#pragma once

class Target
{
public:
    virtual void Request() = 0;
    virtual ~Target() = default;
};