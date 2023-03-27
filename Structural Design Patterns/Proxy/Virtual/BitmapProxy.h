#pragma once
#include "Image.h"
class Bitmap;

class BitmapProxy :
    public Image
{
    Bitmap* m_pBitmap{};
    std::string m_FileName;
    bool m_IsLoaded{ false };
public:
    BitmapProxy();
    BitmapProxy(const std::string fileName);
    ~BitmapProxy();

    void Display() override;
    void Load() override;
    void Load(const std::string& fileName) override;
};

