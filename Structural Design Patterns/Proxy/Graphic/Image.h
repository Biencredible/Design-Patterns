#pragma once
#include "Graphic.h"

/**
 *Real Subject
*/
class Image :public Graphic
{
public: 
    Image(const char* file);
    // Lädt das Bild aus einer Datei
    virtual ~Image();
    virtual void Draw(const Point& at);
    virtual void HandleMouse(Event& event);
    virtual const Point& GetExtent();
    virtual void Load(std::istream& from);
    virtual void Save(std::ostream& to);
private:
    // ...
};