#include "Bitmap.h"
#include <iostream>
#include <stdexcept>
#include <thread>
#include <fstream>

Bitmap::~Bitmap()
{
    std::cout << __FUNCSIG__ << std::endl;
}

void Bitmap::Display()
{
    std::cout << m_Buffer;
}

void Bitmap::Load()
{
    m_Buffer.clear();
    std::ifstream file{ getFileName() };
    if(!file)
    {
        throw std::runtime_error{ "Failed to open file" };
    }
    using namespace std::chrono_literals;
    std::string line{};
    std::cout << "Loading Bitmap[";
    while(std::getline(file, line))
    {
        m_Buffer += line + '\n';
        std::this_thread::sleep_for(100ms);
        std::cout << ".";
    }
    std::cout << "] Done!\n";
}

void Bitmap::Load(const std::string& fileName)
{
    setFileName(fileName);
    Load();
}
