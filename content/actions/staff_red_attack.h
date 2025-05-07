#pragma once

#include "action.h"
#include "item.h"
#include "entity.h"

class Staff_red_attack : public Action {
public:
    Staff_red_attack(Vec direction);
    Result perform(Engine &engine, std::shared_ptr<Entity> entity) override;

private:
    Vec direction;
};