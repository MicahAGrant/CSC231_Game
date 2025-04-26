#pragma once

#include "item.h"
#include "entity.h"

class Staff_green : public Item {
    public:
    Staff_green(int damage);
    void use(Engine &engine, Entity &attacker, Entity& defender) override;

    private:
    int damage;
};