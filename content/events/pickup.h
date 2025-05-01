#pragma once
#include <tile.h>

#include "entity.h"
#include "event.h"

class Pickup : public Event {
public:
    Pickup(Tile& tile, Entity& entity);
    void execute(Engine &engine) override;

private:
    Tile& tile;
    Entity& entity;
};
