#include "TextShape.h"

void TextShapeClassAdapter::BoundingBox(Point& bottomLeft, Point& topRight) const
{
    Coord bottom, left, width, height;
    GetOrigin(bottom, left);
    GetExtent(width, height);

    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
}

bool TextShapeClassAdapter::IsEmpty() const
{
    return TextView::IsEmpty();
}

Manipulator* TextShapeClassAdapter::CreateManipulator () const
{
    return new TextManipulator(this);
}

TextShapeObjectAdapter::TextShapeObjectAdapter(TextView* t)
{
    _text = t;
}

void TextShapeObjectAdapter::BoundingBox(Point& bottomLeft, Point& topRight) const
{
    Coord bottom, left, width, height;
    _text->GetOrigin(bottom, left);
    _text->GetExtent(width, height);

    bottomLeft = Point(bottom, left);
    topRight = Point(bottom + height, left + width);
}

bool TextShapeObjectAdapter::IsEmpty() const
{
    return _text->IsEmpty();
}

Manipulator* TextShapeObjectAdapter::CreateManipulator () const
{
    return new TextManipulator(this);
}



