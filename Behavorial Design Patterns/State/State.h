#pragma once
class Context;

class State
{
protected:
    Context* context_;

public:
    virtual ~State()
    {}

    void set_context(Context* context)
    {
        this->context_ = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

