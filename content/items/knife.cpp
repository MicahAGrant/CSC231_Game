#include "knife.h"
#include "engine.h"
#include "hit.h"

Knife::Knife(int damage)
    : Item{"knife"}, damage{damage} {}

void Knife::use(Engine &engine, Entity &attacker, Entity &defender) {
    engine.events.create_event<Hit>(defender, damage);
}