#include "animationevent.h"
#include "engine.h"

AnimationEvent::AnimationEvent(Vec position, std::string sprite_name)
    :sprite_name{sprite_name}, position{position} {}

void AnimationEvent::execute(Engine &engine) {
    if (frame_count == 0) {
        // get the animation
        sprite = engine.graphics.get_animated_sprite(sprite_name);
        // set the number of frames
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update(); // go to the next frame
}
