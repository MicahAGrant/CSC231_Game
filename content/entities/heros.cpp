#include "heros.h"

#include <iostream>

#include "engine.h"
#include "action.h"
#include "closedoor.h"
#include "move.h"
#include "rest.h"
#include "wander.h"

namespace Heros {
    void make_knight(std::shared_ptr<Entity> hero) {
        hero->set_sprite("knight");
        hero->set_max_health(10);
        hero->behavior = default_behavior;
    }

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity) {
        std::string key = engine.input.get_last_keypress();
        std::cout << key << '\n';
        // if (key == "Right") -> Move({1,0)};
        if (key == "Right") {
            return std::make_unique<Move>(Vec {1,0});
        }
        if (key == "Left") {
            return std::make_unique<Move>(Vec {-1,0});
        }
        if (key == "Up") {
            return std::make_unique<Move>(Vec {0,1});
        }
        if (key == "Down") {
            return std::make_unique<Move>(Vec {0,-1});
        }
        if (key == "R") {
            return std::make_unique<Rest>();
        }
        if (key == "C") {
            return std::make_unique<CloseDoor>();
        }
        else if (key == "Z") {
            return std::make_unique<Wander>();
        }

        return nullptr;
    }
}
