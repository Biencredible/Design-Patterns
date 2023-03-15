#pragma once
class Subject
{
public:
    virtual void Request() = 0;
    virtual ~Subject() = default;
};

