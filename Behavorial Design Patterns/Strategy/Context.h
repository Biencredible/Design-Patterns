#pragma once
#include <iostream>
#include <memory>

class Strategy;

class Context
{
private:
        std::unique_ptr<Strategy> strategy_;

public:
    explicit Context(std::unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy))
    {}

    void set_strategy(std::unique_ptr<Strategy> &&strategy)
    {
        strategy_ = std::move(strategy);
    }

    void doSomeBusinessLogic() const
    {
        if(strategy_)
        {
            std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
            std:: string result = strategy_->doAlgorithm("aecbd");
            std::cout << result << "\n";
        }
        else
        {
            std::cout << "Context: Strategy isn't set.\n";
        }
    }
};

