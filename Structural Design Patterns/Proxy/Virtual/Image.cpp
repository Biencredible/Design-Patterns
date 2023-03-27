#include "Image.h"

void Image::setFileName(const std::string& fileName)
{
    m_FileName = fileName;
}

Image::Image(const std::string& fileName) : m_FileName{fileName}
{
}

const std::string& Image::getFileName() const
{
    return m_FileName;
}
