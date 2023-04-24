#pragma once
#include <string>

class OutputStream
{
public:
    virtual void Write(const std::string& text) = 0;
    virtual void Close() = 0;
    virtual ~OutputStream() = default;
};

