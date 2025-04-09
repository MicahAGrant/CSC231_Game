#pragma once

#include <memory>
#include "entity.h"

namespace Monsters {
    void make_demon(std::shared_ptr<Entity> monster);
    void make_skeleton(std::shared_ptr<Entity> monster);
    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity);
}
