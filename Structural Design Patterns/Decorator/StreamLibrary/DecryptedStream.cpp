#include "DecryptedStream.h"
#include <algorithm>

bool DecryptedStream::Read(std::string& text)
{
    std::string encrypted{};
    const auto result = FileInputStream::Read(encrypted);
    if(!encrypted.empty())
    {
        text.resize((encrypted.size()));
        std::transform(encrypted.begin(), encrypted.end(), text.begin(), [](char ch)
        {
            return ch - 5;
        });
    }
    return result;
}

void DecryptedStream::Close()
{
    FileInputStream::Close();
}
