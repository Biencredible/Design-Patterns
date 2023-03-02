#include "Console.h"
#include <stdexcept>
Console Console::m_Instance;

WORD Console::GetColor(Color color)
{
    switch (color)
    {
        case Color::RED: return FOREGROUND_RED;
        case Color::GREEN: return FOREGROUND_GREEN;
        case Color::BLUE: return FOREGROUND_BLUE;
    }
    return FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
}

Console::Console()
{
    m_Std = GetStdHandle(STD_OUTPUT_HANDLE);
    //if(!GetConsoleScreenBufferInfo(m_Std, &m_consoleBufferInfo))
    //{
    //    throw std::runtime_error{ "Error while retrieving console information" };
    //}
}

//Console::~Console()
//{
//    SetConsoleTextAttribute(m_Std, m_consoleBufferInfo.wAttributes);
//}

void Console::Write(const std::string& text, Color color)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi{};
    if(!GetConsoleScreenBufferInfo(m_Std, &csbi))
    {
        throw std::runtime_error{ "Error while retrieving console information" };
    }
    SetConsoleTextAttribute(m_Std, GetColor(color));
    DWORD written{};
    WriteConsoleA(m_Std, text.c_str(), text.length(), &written, nullptr);
    SetConsoleTextAttribute(m_Std, csbi.wAttributes);
}

void Console::WriteLine(const std::string& text, Color color)
{
    Write(text + '\n', color);
}
