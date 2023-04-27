#pragma once
#include "FileOutputStream.h"
class EncryptedStream :
    public OutputStream
{
    OutputStream* m_pOS;
public:
    void Write(const std::string& text);
    void Close();
};

