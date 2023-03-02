// ConsoleFacade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <string>
#include "Console.h"

int main()
{
   /* HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csinfo{};
    if(!GetConsoleScreenBufferInfo(hConsole, &csinfo))
    {
        std::cout << "Error getting console information\n";
        return -1;
    }
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::string text{ "Hello World!\n" };
    DWORD written{};
    WriteConsoleA(hConsole, text.c_str(), text.length(), &written, nullptr);

    SetConsoleTextAttribute(hConsole, csinfo.wAttributes);
    std::cout << "Using cout.\n";
    printf("Using printf.\n");*/

    Console::WriteLine("Hello World", Color::RED);
    std::cout << "Using cout.\n";
    printf("Using printf.\n");
    Console::Write("Different color", Color::GREEN);
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
