#pragma once
#include "MazeFactory.h"
#include "BombedWall.h"
#include "RoomWithABomb.h"

class BombedMazeFactory :
    public MazeFactory
{
public:
    BombedMazeFactory();

    virtual Wall* MakeWall() const
    {
        return new BombedWall;
    }

    virtual Room* MakeRoom(int n) const
    {
        return new RoomWithABomb(n);
    }
};

