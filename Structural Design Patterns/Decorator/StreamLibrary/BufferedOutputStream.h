#pragma once
#include "FileOutputStream.h"

class BufferedOutputStream :
    public OutputStream
{
    char m_Buffer[512]{};
    OutputStream* m_pOS;
public:
    void Write(const std::string& text) override;
    void Close() override;
};

