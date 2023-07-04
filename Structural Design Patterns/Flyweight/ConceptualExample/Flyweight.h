#pragma once
#include <string>
#include <iostream>

struct SharedState
{
    std::string brand_;
    std::string model_;
    std::string color_;


    SharedState(const std::string& brand, const std::string& model, const std::string& color)
        : brand_(brand),
          model_(model),
          color_(color)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const SharedState &ss)
    {
        return os << "[" << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << "]";
    }
};

struct UniqueState
{
    std::string owner_;
    std::string plates_;


    UniqueState(const std::string& owner, const std::string& plates)
        : owner_(owner),
          plates_(plates)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const UniqueState &us)
    {
        return os << "[" << us.owner_ << " , " << us.plates_ << "]";
    }
};

/**
 * The Flyweight stores a common portion of the state (also called intrinsic state) that belongs to 
 * multiple real business entities. The Flyweight accepts the rest of the state (extrinsic state, 
 * unique for each entity) via its method parameters.
 */
class Flyweight
{
private:
    SharedState* shared_state_;

public:
    Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state))
    {
    }

    Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_))
    {
    }
    ~Flyweight()
    {
        delete shared_state_;
    }
    SharedState *shared_state() const
    {
        return shared_state_;
    }
    void Operation(const UniqueState &unique_state) const
    {
        std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" 
                  << unique_state << ") state.\n";
    }
};

