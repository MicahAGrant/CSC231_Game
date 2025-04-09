#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include <iostream>

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

        for (int i = 0; i < 10; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_demon(monster);
        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
