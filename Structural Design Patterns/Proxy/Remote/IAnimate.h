#pragma once
#include <objbase.h>
class IAnimate
{
public: 
    virtual HRESULT SetImage(unsigned char image) = 0;
    virtual HRESULT Animate(int duration) = 0;
    virtual ~IAnimate() = default;
};

