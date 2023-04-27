#pragma once
#include "FileOutputStream.h"
class EncryptedStream :
    public FileOutputStream
{
    using FileOutputStream::FileOutputStream;
public:
    void Write(const std::string& text) override;
    void Close() override;
};

