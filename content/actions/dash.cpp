#include "dash.h"
#include <vec.h>
#include "engine.h"
#include "entity.h"
#include "opendoor.h"


// Dash::Dash(Vec direction, Door& door)
//     :Action{}, direction{direction}, door{door} {
// }
//
// Result Dash::perform(Engine &engine, std::shared_ptr<Entity> entity) {
//     Tile& tile = engine.dungeon.get_tile(entity->get_position() + direction);
//     if (tile.walkable || (tile.has_door() && tile.door->is_open())) {
//         Vec new_direction = entity->get_position() + direction;
//         entity->move_to(new_direction);
//         entity->change_direction(direction);
//         return success();
//     }
//     else if (tile.has_door() && !tile.door->is_open()) {
//         return alternative(OpenDoor{door});
//     }
//     return failure();
// }
