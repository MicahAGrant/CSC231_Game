#pragma once
#include "entity.h"
#include "event.h"

class Teleport : public Event {
public:
    Teleport(Entity& owner);
    void execute(Engine& engine) override;

private:
    Entity& owner;

};