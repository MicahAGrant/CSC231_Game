#include "animationspin.h"
#include <map>
#include <cmath>

constexpr int duration = 7;

Spin::Spin(Sprite &sprite, Vec direction)
    : Event{duration}, sprite{sprite}, copy{sprite}, starting_angle{sprite.angle} {
    // for each direction, set starting_angle and delta (change in angle)
        starting_angle = 0;
        delta = 360.0 / (duration - 1);
}


void Spin::execute(Engine &engine) {
    sprite.angle = starting_angle + delta * frame_count;
}

void Spin::when_done(Engine&) {
    sprite = copy;
}