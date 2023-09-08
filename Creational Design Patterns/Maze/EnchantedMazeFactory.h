#pragma once
#include "MazeFactory.h"
#include "EnchantedRoom.h"
#include "DoorNeedingSpell.h"
#include "Spell.h"

class EnchantedMazeFactory :
    public MazeFactory
{
public:
    EnchantedMazeFactory();

    virtual Room* MakeRoom(int n) const
    {
        return new EnchantedRoom(n);
    }

    virtual Door* MakeDoor(Room* r1, Room* r2) const
    {
        return new DoorNeedingSpell(r1, r2);
    }

protected:
    Spell* CastSpell() const;
};

