#pragma once

#include "Room.h"

Room::Room(int roomNo) : _roomNumber(roomNo)
{  
}

MapSite* Room::GetSide(Direction) const
{
}

void Room::SetSide(Direction, MapSite*)
{
}

void Room::Enter()
{
}
