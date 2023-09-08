#pragma once
#include <iostream>
#include <list>

#include "IObserver.h"
#include "ISubject.h"
class Subject :
    public ISubject
{
private:
    std::list<IObserver*> list_observer_;
    std::string message_;

public:
    virtual ~Subject()
    {
        std::cout << "Goodbye, I was the SUbject.\n";
    }

    void CreateMessage(std::string message = "Empty")
    {
        this->message_ = message;
        Notify();
    }

    void HowManyObserver() const
    {
        std::cout << "There are " << list_observer_.size() << " observer in the list.\n";
    }

    void Attach(IObserver* observer) override
    {
        list_observer_.push_back(observer);
    }

    void Detach(IObserver* observer) override
    {
        list_observer_.remove(observer);
    }

    void Notify() override
    {
        std::list<IObserver*>::iterator iterator = list_observer_.begin();
        HowManyObserver();
        while(iterator != list_observer_.end())
        {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void someBusinessLogic()
    {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do something important";
    }
};

