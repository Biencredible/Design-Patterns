#pragma once

class Input
{
public:
    virtual bool Up() = 0;
    virtual bool Down() = 0;
    virtual bool Left() = 0;
    virtual bool Right() = 0;
    virtual ~Input() = default;
};
