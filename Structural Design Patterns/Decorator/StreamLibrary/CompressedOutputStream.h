#pragma once
#include "FileOutputStream.h"
class CompressedOutputStream : public OutputStream/*:
    public FileOutputStream*/
{
    OutputStream* m_pOS;
    //using FileOutputStream::FileOutputStream;
public:
    explicit CompressedOutputStream(FileOutputStream* _p_os)
        : m_pOS(_p_os)
    {
    }

    void Write(const std::string& text);
    void Close();
};

