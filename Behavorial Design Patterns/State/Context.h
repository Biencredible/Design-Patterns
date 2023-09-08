#pragma once
#include <iostream>

#include "State.h"
class State;

class Context
{
private:
    State* state_;

public:
    Context(State* state) : state_(nullptr)
    {
        this->TransitionTo(state);
    }

    ~Context()
    {
        delete state_;
    }

    void TransitionTo(State* state)
    {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if(this->state_ != nullptr)
        {
            delete this->state_;
        }
        this->state_ = state;
        this->state_->set_context(this);
    }

    void Request1()
    {
        this->state_->Handle1();
    }

    void Request2()
    {
        this->state_->Handle2();
    }
    void Request3()
    {
        this->state_->Ha
    }
};

