#include "BufferedInputStream.h"
#include <iostream>

bool BufferedInputStream::Read(std::string& text)
{
    auto result = FileInputStream::Read(text);
    std::cout << "Buffered Read\n";
    return result;
}

void BufferedInputStream::Close()
{
    FileInputStream::Close();
}
