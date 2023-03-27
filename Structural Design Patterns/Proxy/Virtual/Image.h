#pragma once
#include <string>

class Image
{
    std::string m_FileName;
protected:
    void setFileName(const std::string& fileName);
public:
    Image() = default;
    Image(const std::string& fileName);
    const std::string& getFileName() const;
    virtual ~Image() = default;
    virtual void Display() = 0;
    virtual void Load() = 0;
    virtual void Load(const std::string& fileName) = 0;
};

