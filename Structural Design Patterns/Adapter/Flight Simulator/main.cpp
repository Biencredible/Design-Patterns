#include "Input.h"
#include <iostream>

void Game(Input* pInput)
{
    int count{5};
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
        std::this_thread::sleep_for(1s)
        --count;
    }
    
}

int main()
{
    Keyboard k;
    Game(&k);
}