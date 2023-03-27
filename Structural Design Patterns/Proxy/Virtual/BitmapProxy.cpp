#include "BitmapProxy.h"
#include "Bitmap.h"
#include <iostream>

BitmapProxy::~BitmapProxy()
{
    delete m_pBitmap;
}

BitmapProxy::BitmapProxy():BitmapProxy{ "" }
{
}

BitmapProxy::BitmapProxy(const std::string fileName)
{
    m_pBitmap = new Bitmap{ fileName };
}

void BitmapProxy::Display()
{
    if(!m_IsLoaded)
    {
        std::cout << "[Proxy] Loading Bitmap\n";
        if(m_FileName.empty())
        {
            m_pBitmap->Load();
        }
        else
        {
            m_pBitmap->Load(m_FileName);
        }
    }
    m_pBitmap->Display();
}

void BitmapProxy::Load()
{
    m_FileName.clear();
}

void BitmapProxy::Load(const std::string& fileName)
{
    m_FileName = fileName;
}
