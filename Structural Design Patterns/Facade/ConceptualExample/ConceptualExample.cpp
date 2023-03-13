// ConceptualExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
 * The subsystem can accept requests either from the facade or client directly.
 * In any case, to the subsystem, the facade is yet another client, and it's not a part of the 
 * subsystem.
 *
 */
class Subsystem1
{
public:
    std::string Operation1() const
    {
        return "Subsystem1: Ready!\n";
    }
    // ...
    std::string OperationN() const
    {
        return "Subsystem1: Go!\n";
    }
};

/**
* Some facades can work with multiple subsystems at the time.
*/
class Subsystem2
{
public:
    std::string Operation1() const
    {
        return "Subsystem2: Ready!\n";
    }
    // ...
    std::string OperationN() const
    {
        return "Subsystem2: Fire!\n";
    }
};

/**
 * The Facade class provides a simple interface to the complex logic of one or 
 * several sbsystems. The Facade delegates the client requests to the 
 * appropriate objecrs within the subsystem. The Facade is also responsible for 
 * managing their lifecycle. All of this shields the client from the undesired
 * complexity of the subsystem.
*/
class Facade
{
protected:
    Subsystem1* subsystem1_;
    Subsystem2* subsystem2_;
    /**
     * Depending on your application's needs, you can eprovide the Facade with existing subsystem 
     * objects or force the Facade to create them on its own.
     */
    Facade(
        Subsystem1* subsystem1 = nullptr,
        Subsystem2* subsystem2 = nullptr)
    {
        this->subsystem1_ = subsystem1 ?: new Subsystem1;
        this->subsystem2_ = subsystem2 ?: new Subsystem2;
    }

    ~Facade()
    {
        delete subsystem1_;
        delete subsystem2_;
    }
    /**
     * The Facade's methods are convenient shortcuts to the suphisticated 
     * functionality of the subsystems. However, clients get only to a fraction of
     * a subsystem's capabilities.
     */
    std::string Operation()
    {
        std::string result = "Facade initializes subsystem:\n";
        result += this->subsystem1_->Operation1();
        result += this->subsystem2_->Operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += this->subsystem1_->OperationN();
        result += this->subsystem2_->OperationN();
        return result;
    }
};

/**
 * The client code works with compley subsystem through a simple interface
 * provided by the Facade. When a facade manages the lifecycle of the subsystem,
 * the client might not even know about the existence of the subsystem. This 
 * approach lets you keep the complexity under control.
 */
void ClientCode(Facade* facade)
{
    // ...
    std::cout << facade->Operation();
    // ...
}

/**
 * The client code may have some of the subsystem's objects already created. In
 * this case, it might be worthwhile to initialize the facade with these objects
 * instead of letting the facade create new instances.
 */

int main()
{
    Subsystem1* subsystem1 = new Subsystem1;
    Subsystem2* subsystem2 = new Subsystem2;
    Facade* facade = new Facade(subsystem1, subsystem2);
    ClientCode(facade);

    delete facade;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
