#include "pickup.h"
#include "entity.h"
#include "item.h"

Pickup::Pickup(Tile &tile, Entity& entity)
    : tile{tile}, entity{entity} {}

void Pickup::execute(Engine &engine) {
    entity.add_to_inventory(tile.item);
    tile.item->interact(engine, entity); // increase/decrease health
    tile.item = nullptr;
}