#include "FileOutputStream.h"

FileOutputStream::FileOutputStream(const std::string& fileName)
{
    m_Writer.open(fileName);
    if(!m_Writer)
    {
        throw std::runtime_error{ "Could not open file for writing" };
    }
}

void FileOutputStream::Write(const std::string & text)
{
    m_Writer << text << '\n';
}

void FileOutputStream::Close()
{
    if(m_Writer.is_open())
    {
        m_Writer.close();
    }
}
