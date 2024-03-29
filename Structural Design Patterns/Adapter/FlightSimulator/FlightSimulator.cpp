// FlightSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <thread>
#include "Keyboard.h"
#include "Input.h"
#include "AccelAdapter.h"

void Game(Input* pInput)
{
    int count = 5;
    while (count !=0)
    {
        using namespace std;
        std::cout << "====================\n";
        if(pInput->Up())
        {
            std::cout << "Pitch up\n";
        }
        else if(pInput->Down())
        {
            std::cout << "Pitch down\n";
        }
        else 
        {
            std::cout << "Plane is level\n";
        }

        if(pInput->Left())
        {
            std::cout << "Plane is turning left\n";
        }
        else if(pInput->Right())
        {
            std::cout << "Plane is turning right\n";
        }
        else
        {
            std::cout << "Plane is flying straight\n";
        }
        std::cout << '\n';
        std::this_thread::sleep_for(1s);
        --count;
    }

}

int main()
{
   // Keyboard k;
   // Game(&k);
    AccelAdapter a;
    Game(&a);
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
