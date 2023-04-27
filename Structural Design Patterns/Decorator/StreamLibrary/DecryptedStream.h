#pragma once
#include "FileInputStream.h"
class DecryptedStream :
    public InputStream
{
    InputStream* m_pIS;

public:
    explicit DecryptedStream(InputStream* _p_is)
        : m_pIS(_p_is)
    {
    }

    bool Read(std::string& text);
    void Close();
};

