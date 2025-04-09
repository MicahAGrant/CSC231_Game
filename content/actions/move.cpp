#include "move.h"
#include "engine.h"
#include "entity.h"
#include <vec.h>
#include "opendoor.h"

Move::Move(Vec direction)
    :Action{}, direction{direction} {
}

Result Move::perform(Engine &engine, std::shared_ptr<Entity> entity) {
    Tile& tile = engine.dungeon.get_tile(entity->get_position() + direction);
        if (tile.walkable || (tile.has_door() && tile.door->is_open())) {
            Vec new_direction  = entity->get_position() + direction;
            entity->move_to(new_direction);
            entity->change_direction(direction);
            return success();
        }
        // else if (tile.has_door() && !tile.door->is_open()) {
        //     return alternative(std::make_unique<OpenDoor>());
        // }
    return failure();
}