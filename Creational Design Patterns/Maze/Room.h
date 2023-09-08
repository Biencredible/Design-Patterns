#pragma once
#include "MapSite.h"
#include "Direction.h"

class Room :
    public MapSite
{
public:
    Room(int roomNo);

    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);

    virtual void Enter() override;

private:
    MapSite* _sides[4];
    int _roomNumber;
};

