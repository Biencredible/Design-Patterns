#pragma once
#include "FileOutputStream.h"

class BufferedOutputStream :
    public FileOutputStream
{
    char m_Buffer[512]{};
    using FileOutputStream::FileOutputStream;
public:
    void Write(const std::string& text) override;
    void Close() override;
};

