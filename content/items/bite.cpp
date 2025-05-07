#include "bite.h"
#include "engine.h"
#include "hit.h"


Bite::Bite(int damage)
    :Item{"none"}, damage{damage} {}

void Bite::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage);
}
