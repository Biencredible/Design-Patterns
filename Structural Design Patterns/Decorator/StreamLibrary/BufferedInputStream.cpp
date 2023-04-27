#include "BufferedInputStream.h"
#include <iostream>

bool BufferedInputStream::Read(std::string& text)
{
    auto result = m_pIS->Read(text);
    std::cout << "Buffered Read\n";
    return result;
}

void BufferedInputStream::Close()
{
    m_pIS->Close();
}
