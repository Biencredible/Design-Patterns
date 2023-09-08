#pragma once
#include "MapSite.h"
#include "Room.h"

class Door :
    public MapSite
{
public:
    Door();
    Door(const Door& other);
    Door(Room* = 0, Room* = 0);

    virtual void Initialize(Room*, Room*);
    virtual Door* Clone() const;
    virtual void Enter() override;
    Room* OtherSideFrom(Room*);

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

