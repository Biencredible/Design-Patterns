#pragma once
#include "FileInputStream.h"
class BufferedInputStream :
    public InputStream
{
    char m_Buffer[512]{};
    InputStream* m_pIS;

public:
    explicit BufferedInputStream(InputStream* _p_is)
        : m_pIS(_p_is)
    {
    }

    bool Read(std::string& text);
    void Close();
};

