#include "staff_red.h"

#include "action.h"
#include "animationevent.h"
#include "animationspin.h"
#include "audioevent.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
#include "swing.h"

Staff_red::Staff_red(int damage)
    :Item{"staff_red"}, damage{damage}/*, direction{direction}*/ {}

void Staff_red::use(Engine &engine, Entity &attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Thrust> animation = engine.events.create_event<Thrust>(sprite, direction);

    for (int i = 1; i < 5; i++) {
        Vec tile = attacker.get_position() + i*direction;
        Tile& enemy_tile = engine.dungeon.get_tile(attacker.get_position() + i*direction);
        if (enemy_tile.has_entity()) {
            animation->add_next<Hit>(*enemy_tile.entity, damage);
            animation->add_next<AnimationEvent>(tile, "fire");
            animation->add_next<AudioEvent>("fire");
        }

    }
}