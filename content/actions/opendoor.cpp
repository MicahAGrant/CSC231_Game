#include "opendoor.h"
#include "entity.h"
#include "engine.h"
#include "updatefov.h"
#include <vec.h>

OpenDoor::OpenDoor(Door& door)
    :Action{}, door{door} {

}

Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    door.open();
    bool closed_any_doors{false};
    // Vec direction = entity->get_position();
    // bool closed_any_doors{true};
    // Tile& tile = engine.dungeon.get_tile(direction);
    // if (tile.has_door() && !tile.door->is_open()) {
    //     tile.door->open();
    //     closed_any_doors = false;
    // }

    // for (Vec neighbor : engine.dungeon.neighbors(position)) {
    //     Tile& tile = engine.dungeon.get_tile(neighbor);
    //     if (tile.has_door() && !tile.door->is_open()) {
    //         // tile has door and it is open
    //         tile.door->open();
    //         closed_any_doors = false;
    //         break;
    //     }
    // }
    // if we open any doors, update FOV
    if (!closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure();
    }
}