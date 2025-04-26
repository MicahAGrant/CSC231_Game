#include "attack.h"
#include "entity.h"
#include "item.h"
#include "rest.h"

Attack::Attack(Entity& defender)
    : defender{defender} {}

Result Attack::perform(Engine &engine, std::shared_ptr<Entity> attacker) {
    auto weapon = attacker->get_current_item();
    if (weapon) {
        weapon->use(engine, *attacker, defender);
        return success();
    }
    else alternative(Rest{});
}
