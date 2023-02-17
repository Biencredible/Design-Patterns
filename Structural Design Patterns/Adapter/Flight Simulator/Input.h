#pragma once

class Input
{
private:
    /* data */
public:
    virtual bool Up() = 0;
    virtual bool Down() = 0;
    virtual bool Left() = 0;
    virtual bool Right() = 0;
    virtual ~Input() = default;
};

Input::Input(/* args */)
{
}

Input::~Input()
{
}
