#include "engine.h"
#include "heros.h"
#include "monsters.h"
#include <iostream>
#include <randomness.h>

#include "entity.h"
#include "potion.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heros::make_knight(hero);

        for (int i = 0; i < 2; ++i) {
            Vec position = engine.dungeon.random_open_room_tile();
            Tile& tile = engine.dungeon.get_tile(position);
            tile.item = std::make_shared<Potion>(-3);
            tile.item->sprite = engine.graphics.get_sprite(tile.item->name);
        }

        for (int i = 0; i < 20; ++i) {
            if (probability(50)) {
                if (probability(50)) {
                    std::shared_ptr<Entity> monster = engine.create_monster();
                    Monsters::make_demon(monster);
                }
                else {
                    std::shared_ptr<Entity> monster3 = engine.create_monster();
                    Monsters::make_muddy(monster3);
                }
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
