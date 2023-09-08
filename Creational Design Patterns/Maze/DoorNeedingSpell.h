#pragma once
#include "Door.h"
class DoorNeedingSpell :
    public Door
{
public:
    DoorNeedingSpell(Room* = 0, Room* = 0);
};

