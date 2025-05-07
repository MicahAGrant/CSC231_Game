#include "staff_red_attack.h"
#include "animationevent.h"
#include "animationspin.h"
#include "attack.h"
#include "audioevent.h"
#include "engine.h"
#include "hit.h"
#include "entity.h"
#include "rest.h"
#include "thrust.h"

Staff_red_attack::Staff_red_attack(Vec direction)
    :Action{}, direction{direction}{}

Result Staff_red_attack::perform(Engine &engine, std::shared_ptr<Entity> entity) {
    int damage {5};
    auto weapon = entity->get_current_item();
    if (weapon->name != "staff_red") {
        return failure();
    }
    std::shared_ptr<Thrust> animation = engine.events.create_event<Thrust>(weapon->sprite, direction);
        for (int i = 1; i < 5; i++) {
            Tile& tile = engine.dungeon.get_tile(entity->get_position() + i*direction);
            Vec tile2 = (entity->get_position() + i*direction);
            std::cout << i*direction;
            if (weapon) {
                weapon->use(engine, *entity);
                if (tile.is_wall()) {
                    return failure();
                }
                if (tile.has_entity()) {
                    animation->add_next<Hit>(*tile.entity, damage);
                    animation->add_next<AnimationEvent>(tile2, "fire");
                    animation->add_next<AudioEvent>("fire");
                }
            }
        }
    return success();
 }