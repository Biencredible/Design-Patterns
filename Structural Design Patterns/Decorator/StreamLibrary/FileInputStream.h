#pragma once
#include "InputStream.h"
#include <fstream>

class FileInputStream :
    public InputStream
{
    std::ifstream m_Reader;
public:
    FileInputStream() = default;
    FileInputStream(const std::string& fileName);
    bool Read(std::string& text) override;
    void Close() override;
};

