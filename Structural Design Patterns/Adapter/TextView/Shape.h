#pragma once

/**
 * Shape is defined by a Boundingbox, which is defined by its opposite corners.
 */
class Shape
{
public:
    Shape();
    virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
    virtual Manipulator* CreateManipulator() const;
};

