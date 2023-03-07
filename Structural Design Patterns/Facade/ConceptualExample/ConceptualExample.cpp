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

int main()
{
    std::cout << "Hello World!\n";
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
