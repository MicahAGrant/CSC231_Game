#pragma once

#include "entity.h"
#include "item.h"


class Sword_red_gem : public Item {
public:
    Sword_red_gem(int damage);
    void use(Engine &engine, Entity &attacker, Entity& defender) override;

private:
    int damage;
};