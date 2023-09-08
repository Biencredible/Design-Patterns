#include "Door.h"
#include <iostream>

Door::Door(Room* room1, Room* room2) : _room1(room1), _room2(room2)
{
}

void Door::Enter()
{
    if(_isOpen)
        std::cout << "Entered Door.\n";
    else
        std::cout << "Door is closed.\n";

}

Room* Door::OtherSideFrom(Room*)
{
}

Door::Door(const Door& other)
{
    _room1 = other._room1;
    _room2 = other._room2;
}

Door* Door::Clone () const
{
    return new Door(*this);
}
