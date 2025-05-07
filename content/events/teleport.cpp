#include "teleport.h"

#include <tile.h>

#include "engine.h"

Teleport::Teleport(Entity &owner)
    : owner{owner} {}

void Teleport::execute(Engine &engine) {
    // get owner's position then finds a random tile
    // and teleports the owner to that tile
    Vec randomtile = engine.dungeon.random_open_room_tile();
    owner.move_to(randomtile);
}

