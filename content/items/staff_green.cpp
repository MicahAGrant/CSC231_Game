#include "staff_green.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
#include "swing.h"

Staff_green::Staff_green(int damage)
    :Item{"staff_green"}, damage{damage} {}

void Staff_green::use(Engine &engine, Entity &attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.create_event<Thrust>(sprite, direction);
    engine.events.create_event<Hit>(defender, damage);
    //engine.events.create_event<Swing>(sprite, direction);
}