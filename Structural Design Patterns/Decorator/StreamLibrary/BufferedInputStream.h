#pragma once
#include "FileInputStream.h"
class BufferedInputStream :
    public FileInputStream
{
    char m_Buffer[512]{};
    using FileInputStream::FileInputStream;

public:
    bool Read(std::string& text) override;
    void Close() override;
};

