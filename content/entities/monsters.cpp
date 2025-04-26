#include "monsters.h"
#include <randomness.h>
#include "engine.h"
#include "entity.h"
#include "knife.h"
#include "move.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {
    void make_demon(std::shared_ptr<Entity> monster) {
        monster->set_sprite("demon_big");
        monster->set_max_health(40);
        monster->set_team(Team::Monster);
        monster->behavior = default_behavior;
    }

    void make_skeleton(std::shared_ptr<Entity> monster) {
        monster->set_sprite("skeleton");
        monster->set_max_health(10);
        monster->set_team(Team::Monster);
        monster->behavior = default_behavior;

        // monster weapon
        monster->add_to_inventory(std::make_shared<Knife>(1));
    }

    void make_muddy(std::shared_ptr<Entity> monster) {
        monster->set_sprite("muddy");
        monster->set_max_health(20);
        monster->set_team(Team::Monster);
        monster->behavior = default_behavior;
    }

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity) {
        if (entity.is_visible() && engine.hero) {
            std::vector<Vec> path = engine.dungeon.calculate_path(entity.get_position(),
                                                                  engine.hero->get_position());
            if (path.size() > 1) { // at least one tile away, pursue hero
                Vec direction = path.at(1) - path.at(0); // 0 is entity's position
                return std::make_unique<Move>(direction);
            }
        }

        // not visible
        if (probability(66)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
    }

}
