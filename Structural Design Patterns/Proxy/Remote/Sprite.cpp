#include "Sprite.h"
#include <iostream>

HRESULT Sprite::SetImage(unsigned char image)
{
    m_Image = image;
    return S_OK;
}

HRESULT Sprite::Animate(int duration)
{
    for(int i = 0; i< duration; ++i)
    {
        std::cout << m_Image;
        Sleep(1000);
    }
    return S_OK;
}
