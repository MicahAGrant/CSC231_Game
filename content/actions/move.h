#pragma once
#include <door.h>
#include <vec.h>
#include "action.h"

class Move : public Action {
public:
    Move(Vec direction/*, Door& door */);
    Result perform(Engine &engine, std::shared_ptr<Entity> entity) override;

private:
    Vec direction;
    // Door& door;

};
