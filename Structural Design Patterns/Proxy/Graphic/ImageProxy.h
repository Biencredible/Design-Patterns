#pragma once
#include "Graphic.h"
#include "Image.h"

/**
 * Virtual Proxy
 */
class ImageProxy :
    public Graphic
{
public:
    ImageProxy(const char* fileName);
    virtual ~ImageProxy();

    virtual void Draw(const Point& at);
    virtual void HandleMouse(Event& event);

    virtual const Point& GetExtent();

    virtual void Load(std::istream& from);
    virtual void Save(std::ostream& to);

protected:
    Image* GetImage();

private:
    Image* _image;
    Point _extent;
    char* _fileName;
};

