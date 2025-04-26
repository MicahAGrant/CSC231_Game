#include "move.h"
#include "engine.h"
#include "entity.h"
#include <vec.h>

#include "attack.h"
#include "opendoor.h"
#include "rest.h"

Move::Move(Vec direction)
    :Action{}, direction{direction} {
}

Result Move::perform(Engine &engine, std::shared_ptr<Entity> entity) {
    Tile& tile = engine.dungeon.get_tile(entity->get_position() + direction);
    // if (tile.walkable || (tile.has_door() && tile.door->is_open())) {
    // if (!tile.is_wall() && !tile.has_door() && !tile.has_entity()) {
    //     Vec new_direction  = entity->get_position() + direction;
    //     entity->move_to(new_direction);
    //     entity->change_direction(direction);
    //     return success();
    // }
    if (tile.is_wall()) {
        return failure();
    }
    else if (tile.has_entity() && entity->get_team() == tile.entity->get_team()) {
        return alternative(Rest{});
    }
    else if (tile.has_door() && !tile.door->is_open()) {
        return alternative(OpenDoor{*tile.door});
    }
    else if (tile.has_entity() && (entity->get_team() != tile.entity->get_team())) {
        return alternative(Attack{*tile.entity});
    }
    else {
        Vec new_direction  = entity->get_position() + direction;
        entity->move_to(new_direction);
        entity->change_direction(direction);
        return success();
    }
    return failure();
}