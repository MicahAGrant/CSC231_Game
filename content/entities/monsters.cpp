#include "monsters.h"

#include <randomness.h>

namespace Monsters {
    void make_demon(std::shared_ptr<Entity> monster) {
        monster->set_sprite("demon_big");
        monster->set_max_health(40);
        monster->behavior;
    }

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity) {
        probability(66);
    }

}
