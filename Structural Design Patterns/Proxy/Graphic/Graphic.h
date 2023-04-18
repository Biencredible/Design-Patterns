#pragma once
#include <istream>

/**
 * Graphic is the interface for graphical objects.
*/
class Graphic
{
public:
    virtual ~Graphic();
    virtual void Draw(const Point& at) = 0;
    virtual void HandleMouse(Event& event) = 0;
    virtual const Point& GetExtent() = 0;
    virtual void Load(std::istream& from) = 0;
    virtual void Save(std::ostream& to) = 0;

protected:
    Graphic();
};


