#pragma once

#include "../../engine/action.h"

class OpenDoor : public Action {
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
};