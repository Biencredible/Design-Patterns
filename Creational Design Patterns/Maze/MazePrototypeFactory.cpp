#include "MazePrototypeFactory.h"

MazePrototypeFactory::MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d)
    : _prototypeMaze(m), _prototypeWall(w), _prototypeRoom(r), _prototypeDoor(d)
{

}

Maze* MazePrototypeFactory::MakeMaze() const
{
    return _prototypeMaze->Clone();
}

Wall* MazePrototypeFactory::MakeWall() const
{
    return _prototypeWall->Clone();
}

Room* MazePrototypeFactory::MakeRoom(int n) const
{
    Room* room = _prototypeRoom->Clone();
    room->Initialize(n);
    return room;
}

Door* MazePrototypeFactory::MakeDoor(Room* r1, Room* r2) const
{
    Door* door = _prototypeDoor->Clone();
    door->Initialize(r1, r2);
    return door;
}
