#include "teleport_potion.h"

#include "engine.h"
#include "entity.h"
#include "teleport.h"

TeleportPotion::TeleportPotion()
    : Item{"potion_blue"} {}

void TeleportPotion::use(Engine& engine, Entity& owner) {
    engine.events.create_event<Teleport>(owner);
    owner.remove_item(owner.get_current_item().get());
}

void TeleportPotion::interact(Engine& engine, Entity& entity) {}