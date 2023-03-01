#pragma once

/**
 * TextView is defined by its point of origin, width and height.
 */
class TextView
{
public:
    TextView();
    void GetOrigin(Coord& x, Coord& y) const;
    void GetExtent(Coord& width, Coord& height) const;
    virtual bool IsEmpty() const;
};

