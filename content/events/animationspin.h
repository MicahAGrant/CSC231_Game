#pragma once

#include "event.h"
#include "vec.h"
#include "sprite.h"

class Spin : public Event {
public:
    Spin(Sprite& sprite, Vec direction);

    void execute(Engine &engine) override;
    void when_done(Engine &engine) override;

    Sprite& sprite; // by reference (refers to the one stored in the entity's object)
    Sprite copy; // by value
    double starting_angle, delta;
};