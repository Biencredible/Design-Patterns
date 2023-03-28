#pragma once
#include <string>

class Storage
{
public:
    virtual void CreateFile(const std::string &fileName) = 0;
    virtual void DeleteFile(const std::string &fileName) = 0;
    virtual void UpdateFile(const std::string &fileName) = 0;
    virtual void ViewFile(const std::string &fileName) = 0;
    virtual ~Storage() = default;
};

