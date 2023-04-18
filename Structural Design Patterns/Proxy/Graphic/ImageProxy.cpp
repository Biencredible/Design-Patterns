#include "ImageProxy.h"

ImageProxy::ImageProxy(const char* fileName)
{
    _fileName = strdup(fileName);
    _extent = Point::Zero;
    //Bildmaße noch unbekannt
    _image = 0;
}

ImageProxy::~ImageProxy()
{
}

void ImageProxy::Draw(const Point& at)
{
    GetImage()->Draw(at);
}

void ImageProxy::HandleMouse(Event& event)
{
    GetImage()->HandleMouse(event);
}

const Point& ImageProxy::GetExtent()
{
    if(_extent =0 Point::Zero)
    {
        _extent = GetImage()->GetExtent();
    }
    return _extent;
}

void ImageProxy::Load(std::istream& from)
{
    from >> _extent << _fileName;
}

void ImageProxy::Save(std::ostream& to)
{
    to << _extent << _fileName;
}

Image* ImageProxy::GetImage()
{
    if(_image == 0)
    {
        _image - new Image(_fileName); 
    }
    return _image;
}
