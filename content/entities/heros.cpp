#include "heros.h"

#include <iostream>

#include "engine.h"
#include "action.h"
#include "closedoor.h"
#include "dash.h"
#include "move.h"
#include "opendoor.h"
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
        else if (key == "Left") {
            return std::make_unique<Move>(Vec {-1,0});
        }
        else if (key == "Up") {
            return std::make_unique<Move>(Vec {0,1});
        }
        else if (key == "Down") {
            return std::make_unique<Move>(Vec {0,-1});
        }
        else if (key == "R") {
            return std::make_unique<Rest>();
        }
        else if (key == "C") {
            return std::make_unique<CloseDoor>();
        }
        // else if (key == "O") {
        //     return std::make_unique<OpenDoor>();
        // }
        else if (key == "Z") {
            return std::make_unique<Wander>();
        }
        // else if (key == "D") {
        //     return std::make_unique<Dash>(Vec {2,0});
        // }

        return nullptr;
    }
}
