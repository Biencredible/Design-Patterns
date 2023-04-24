#include "BufferedOutputStream.h"
#include <iostream>

void BufferedOutputStream::Write(const std::string& text)
{
    std::cout << "Buffered Write\n";
    FileOutputStream::Write(text);
}

void BufferedOutputStream::Close()
{
    FileOutputStream::Close();
}
