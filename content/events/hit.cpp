#include "hit.h"
#include "engine.h"
#include "entity.h"
#include "die.h"

Hit::Hit(Entity& entity, int damage)
    : entity{entity}, damage{damage} {}

void Hit::execute(Engine&) {
    // add an audio event for the hit
    entity.take_damage(damage);
}

void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        // add_next(Die{entity}); //old version
        add_next<Die>(entity);
    }
}
