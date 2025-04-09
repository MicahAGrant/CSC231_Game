//
// Created by grant on 4/4/2025.
//

#include "closedoor.h"

#include <iostream>

#include "entity.h"
#include "engine.h"
#include "updatefov.h"
#include <vec.h>


Result CloseDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    bool closed_any_doors{false};
    for (Vec neighbor : engine.dungeon.neighbors(position)) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && tile.door->is_open()) {
            // tile has door and it is closed
            tile.door->close();
            closed_any_doors = true;
        }
        else if (tile.has_door() && !tile.door->is_open()) {
            tile.door->open();
        }
    }
    // if we closed any doors, update FOV
    if (closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else if (!closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure();
    }

    return success();
}
