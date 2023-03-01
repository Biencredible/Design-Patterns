#pragma once
#include "Shape.h"
#include "TextView.h"

/**
 * Textshape is the Adapter between Shape and TextView
 */
class TextShapeClassAdapter :
    public Shape, private TextView
{
public:
    TextShapeClassAdapter();
    /*
     * BoundingBox converts the Interface of TextView in a way that it is the same as the interface 
     * of Shape.
     */
    virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;
    
    virtual bool IsEmpty() const;
    virtual Manipulator* createManipulator() const;
};

class TextShapeObjectAdapter :
    public Shape
{
public:
    TextShapeObjectAdapter(TextView*);
    /*
    * BoundingBox converts the Interface of TextView in a way that it is the same as the interface 
    * of Shape.
    */
    virtual void BoundingBox(Point& bottomLeft, Point& topRight) const;

    virtual bool IsEmpty() const;
    virtual Manipulator* createManipulator() const;

private:
    TextView* _text;
};


