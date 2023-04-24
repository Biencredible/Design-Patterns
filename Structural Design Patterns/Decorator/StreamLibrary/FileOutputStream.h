#pragma once
#include "OutputStream.h"
#include <fstream>

class FileOutputStream :
    public OutputStream
{
    std::ofstream m_Writer{};
public:
    FileOutputStream() = default;
    FileOutputStream(const std::string& fileName);
    void Write(const std::string& text) override;
    void Close() override;
};

