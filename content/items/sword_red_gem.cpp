#include "sword_red_gem.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"
#include "swing.h"

Sword_red_gem::Sword_red_gem(int damage)
    :Item{"sword_red_gem"}, damage{damage} {}

void Sword_red_gem::use(Engine &engine, Entity &attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.create_event<Thrust>(sprite, direction);
    engine.events.create_event<Hit>(defender, damage);
    engine.events.create_event<Swing>(sprite, direction);
    //engine.events.create_event<Hit>(defender, damage/2);
    //engine.create_monster();
}