#pragma once
#include "IAnimate.h"

class Sprite:
public IAnimate
{
    unsigned char m_Image;
public:

    HRESULT SetImage(unsigned char image) override;
    HRESULT Animate(int duration) override;
};

