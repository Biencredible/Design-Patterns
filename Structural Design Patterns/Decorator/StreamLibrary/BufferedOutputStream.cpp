#include "BufferedOutputStream.h"
#include <iostream>

void BufferedOutputStream::Write(const std::string& text)
{
    std::cout << "Buffered Write\n";
    m_pOS->Write(text);
}

void BufferedOutputStream::Close()
{
    m_pOS->Close();
}
