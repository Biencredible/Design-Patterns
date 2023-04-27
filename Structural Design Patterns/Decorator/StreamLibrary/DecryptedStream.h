#pragma once
#include "FileInputStream.h"
class DecryptedStream :
    public FileInputStream
{
    using FileInputStream::FileInputStream;

public:
    bool Read(std::string& text) override;
    void Close() override;
};

