#pragma once
#include "MazeFactory.h"
class MazePrototypeFactory :
    public MazeFactory
{
public:
    MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

    virtual Maze* MakeMaze() const;

    virtual Wall* MakeWall() const;

    virtual Room* MakeRoom(int n) const;

    virtual Door* MakeDoor(Room* r1, Room* r2) const;

private:
    Maze* _prototypeMaze;
    Wall* _prototypeWall;
    Room* _prototypeRoom;
    Door* _prototypeDoor;
};


