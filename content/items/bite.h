#pragma once

#include "item.h"

class Engine;
class Entity;

class Bite : public Item {
public:
    Bite(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};
