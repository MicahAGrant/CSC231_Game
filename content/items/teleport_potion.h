#pragma once

#include "entity.h"
#include "item.h"

class TeleportPotion : public Item {
public:
    TeleportPotion();
    void use(Engine& engine, Entity& owner) override;
    void interact(Engine& engine, Entity& entity);

private:
    
};