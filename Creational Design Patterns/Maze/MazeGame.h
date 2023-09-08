#pragma once
#include "Maze.h"
#include "MazeFactory.h"
#include "MazeBuilder.h"

class MazeGame
{
    static Maze* CreateMaze();
    static Maze* CreateMaze(MazeFactory& factory);
    static Maze* CreateMaze(MazeBuilder& builder);
    static Maze* CreateComplexMaze(MazeBuilder& builder);

    //Factory Methods
    virtual Maze* MakeMaze() const { return new Maze; }
    virtual Room* MakeRoom(int n) const { return new Room(n); }
    virtual Wall* MakeWall() const { return new Wall; }
    virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

