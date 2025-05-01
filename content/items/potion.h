#pragma once

#include "entity.h"
#include "item.h"

class Potion : public Item {
public:
    Potion(int healing_amount);
    void use(Engine& engine, Entity& owner) override;
    void interact(Engine& engine, Entity& entity);

private:
    int healing_amount;
};