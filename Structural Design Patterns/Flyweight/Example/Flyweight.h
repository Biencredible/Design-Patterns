#pragma once
class Flyweight
{
public:
    virtual void Operation(int extrinsic) = 0;
    virtual ~Flyweight() = default;
};

