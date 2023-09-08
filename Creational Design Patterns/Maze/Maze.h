#pragma once
#include "Room.h"

class Maze
{
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const;

    private:
    // ...
};

