#include "AudioFacade.h"
AudioFacade::AudioFacade()
{
	wrapper = std::make_unique<AudioWrapper>();
}

void AudioFacade::playAudio(const std::string& path, bool loop) const
{
	wrapper->playAudio(path, loop);
}