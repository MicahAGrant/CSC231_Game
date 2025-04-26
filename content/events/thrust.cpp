#include "thrust.h"
#include <map>

const std::map<Vec, double> direction_to_angle = {
    {{0,1}, 0}, // direction whose key corresponds to y value
    {{1,0}, 90},
    {{0,-1}, 180},
    {{-1,0}, 270}
};

// constexpr is for small integers
constexpr int delta = 3; // pixels to shift per frame
constexpr int duration = 3; // number of frames

Thrust::Thrust(Sprite& sprite, Vec direction)
    : Event{duration}, sprite{sprite}, copy{sprite}, direction{direction} {
    sprite.angle = direction_to_angle.at(direction);
    // if looking for the same type of data type, create a function that instead finds it(?)

    // if (direction == Vec{0,1}) {
    //     sprite.angle = 0;
    // }
    // else if (direction == Vec{1,0}) {
    //     sprite.angle = 90;
    // }
    // else if (direction == Vec{0,-1}) {
    //     sprite.angle = 180;
    // }
    // else { // left
    //     sprite.angle = 270;
    // }
}

void Thrust::execute(Engine &engine) {
    sprite.shift += direction * delta;
}

void Thrust::when_done(Engine&) {
    sprite = copy;
}

