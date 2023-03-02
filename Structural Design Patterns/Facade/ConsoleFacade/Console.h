#pragma once
#include <string>
#include <windows.h>

enum class Color { RED, GREEN, BLUE, WHITE};

class Console
{
    inline static HANDLE m_Std;
    //CONSOLE_SCREEN_BUFFER_INFO m_consoleBufferInfo{};
    static Console m_Instance;
    static WORD GetColor(Color color);
    Console();
public:  
    /*~Console();*/
    static void Write(const std::string &text, Color color = Color::WHITE);
    static void WriteLine(const std::string &text, Color color = Color::WHITE);
};

