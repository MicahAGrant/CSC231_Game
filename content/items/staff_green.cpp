#include "staff_green.h"

#include "animationevent.h"
#include "animationspin.h"
#include "audioevent.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
#include "swing.h"

Staff_green::Staff_green(int damage)
    :Item{"staff_green"}, damage{damage} {}

void Staff_green::use(Engine &engine, Entity &attacker, Entity& defender) {
    //auto thing;
    Vec direction = defender.get_position() - attacker.get_position();
    std::shared_ptr<Spin> animation = engine.events.create_event<Spin>(sprite, direction);
    // engine.events.create_event<Thrust>(sprite, direction);
    // engine.events.create_event<Hit>(defender, damage);

    std::vector<Vec> area {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1},
        {1,1},
        {1,-1},
        {-1,1},
        {-1,-1}
    };

    for (int i = 0; i < area.size(); i++) {
        Vec new_pos = attacker.get_position() + area.at(i);
        Tile& tile = engine.dungeon.get_tile(attacker.get_position() + area.at(i));
        if (tile.has_entity()) {
            animation->add_next<Hit>(defender, damage);
            animation->add_next<AnimationEvent>(new_pos, "lightning");
            animation->add_next<AudioEvent>("thunder");
        }
    }
    //engine.events.create_event<Swing>(sprite, direction);
}