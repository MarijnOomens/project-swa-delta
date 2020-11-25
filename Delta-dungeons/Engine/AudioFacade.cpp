#include "AudioFacade.h"

void AudioFacade::playAudio(const std::string& path, bool loop) const
{
	wrapper->playAudio(path, loop);
}