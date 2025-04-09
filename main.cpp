#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include <iostream>
#include <randomness.h>

#include "entity.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        // hero->set_sprite("knight");
        // Vec pos = hero->get_position();
        // Tile& tile = engine.dungeon.get_tile(pos);
        // Vec new_position = pos + Vec{1,1};
        // std::cout << hero->get_position() << '\n';
        Heros::make_knight(hero);

        for (int i = 0; i < 20; ++i) {
            if (probability(20)) {
                std::shared_ptr<Entity> monster = engine.create_monster();
                Monsters::make_demon(monster);

            }
            else {
                std::shared_ptr<Entity> monster2 = engine.create_monster();
                Monsters::make_skeleton(monster2);
            }
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
