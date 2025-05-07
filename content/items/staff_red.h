#pragma once

#include "item.h"
#include "entity.h"

class Staff_red : public Item {
public:
    Staff_red(int damage);
    void use(Engine &engine, Entity &attacker, Entity& defender) override;

private:
    int damage;
};