#pragma once
#include <unordered_map>
#include "Flyweight.h"


/**
 * The Flyweight Factory creats and manages the Flyweight objects. It ensures
 * that flyweíghts are shared correctly. When the client requests a flyweight,
 * the factory either returns an exisitng instance or creates a new one, if it 
 * doesn't exist yet.
 */
class FlyweightFactory
{
    /**
     * @var Flyweight []
     */
private:
    std::unordered_map<std::string, Flyweight> flyweights_;
    /**
     * Returns a Flyweight's string hash for a given state.
     */

    std::string GetKey(const SharedState& ss) const
    {
        return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
    }

public:
    FlyweightFactory(std::initializer_list<SharedState> share_states)
    {
        for (const SharedState& ss : share_states)
        {
            this->flyweights_.insert(std::make_pair<std::string, Flyweight> 
                                     (this->GetKey(ss), Flyweight(&ss)));
        }
    }

    /**
     * Returns an existing Flyweight with a given state or creates a new one.
     */
    Flyweight GetFlyweight(const SharedState& shared_state)
    {
        std::string key = this->GetKey(shared_state);
        if(this->flyweights_.find(key) == this->flyweights_.end())
        {
            std::cout << "FlyweightFactory: Can't find a flyweight, creating"
                << "new one.\n";
            this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
        }
        return this->flyweights_.at(key);
    }

    void ListFlyweights() const
    {
        size_t count = this->flyweights_.size();
        std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
        for(std::pair<std::string, Flyweight> pair : this->flyweights_)
        {
            std::cout << pair.first << "\n";
        }
    }
};

