#pragma once
#include <animatedsprite.h>
#include <vec.h>
#include "event.h"

class AnimationEvent : public Event {
public:
    AnimationEvent(Vec position, std::string sprite_name);
    void execute(Engine &engine) override;

private:
    Vec position;
    std::string sprite_name;
    AnimatedSprite sprite;
};