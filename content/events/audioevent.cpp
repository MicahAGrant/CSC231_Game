#include "audioevent.h"
#include "engine.h"

AudioEvent::AudioEvent(std::string name)
    : name{name} {}

void AudioEvent::execute(Engine &engine) {
    engine.audio.play_sound(name);
}