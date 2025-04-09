#include "opendoor.h"
#include "entity.h"
#include "engine.h"
#include "updatefov.h"
#include <vec.h>


Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    bool closed_any_doors{true};
    for (Vec neighbor : engine.dungeon.neighbors(position)) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && !tile.door->is_open()) {
            // tile has door and it is open
            tile.door->open();
            closed_any_doors = false;
        }
    }
    // if we open any doors, update FOV
    if (!closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure();
    }
}