#pragma once
#include "FileInputStream.h"
class DecompressedInputStream /*:
    public FileInputStream*/
{
    FileInputStream *m_pIS;
   // using FileInputStream::FileInputStream;

public:
    explicit DecompressedInputStream(FileInputStream* _p_is)
        : m_pIS(_p_is)
    {
    }

    bool Read(std::string& text);
    void Close();
};

