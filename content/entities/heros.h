#pragma once
#include "entities.h"
#include "entity.h"


namespace Heros {

    void make_knight(std::shared_ptr<Entity> hero);

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity);
}
