#include "heros.h"
#include <iostream>
#include "engine.h"
#include "action.h"
#include "attack.h"
#include "closedoor.h"
#include "dash.h"
#include "move.h"
#include "rest.h"
#include "wander.h"
#include "potion.h"
#include "staff_green.h"
#include "staff_red.h"
#include "staff_red_attack.h"
#include "use.h"
#include "sword_red_gem.h"
#include "teleport_potion.h"

namespace Heros {
    void make_knight(std::shared_ptr<Entity> hero) {
        hero->set_sprite("knight");
        hero->set_max_health(20);
        hero->behavior = default_behavior;
        hero->set_team(Team::Hero);

        // starting items
        hero->add_to_inventory(std::make_shared<Potion>(-3));
        hero->add_to_inventory(std::make_shared<Sword_red_gem>(5));
        hero->add_to_inventory(std::make_shared<Staff_green>(3));
        hero->add_to_inventory(std::make_shared<Staff_red>(5));
        hero->add_to_inventory(std::make_shared<TeleportPotion>());
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
        if (key == "Z") {
            return std::make_unique<Wander>();
        }
        if (key == "W") {
            return std::make_unique<Staff_red_attack>(Vec {0,1});
        }
        if (key == "A") {
            return std::make_unique<Staff_red_attack>(Vec {-1,0});
        }
        if (key == "S") {
            return std::make_unique<Staff_red_attack>(Vec {0,-1});
        }
        if (key == "D") {
            return std::make_unique<Staff_red_attack>(Vec {1,0});
        }
        if (key == "E") {
            entity.switch_to_next_item();
        }
        else if (!key.empty() && std::isdigit(key.at(0))) { // gets a number
            int index = std::stoi(key);
            entity.select_item(index);
        }
        else if (key == "U") {
            return std::make_unique<Use>();
        }
        // else if (key == "D") {
        //     return std::make_unique<Dash>(Vec {2,0});
        // }

        return nullptr;
    }
}
