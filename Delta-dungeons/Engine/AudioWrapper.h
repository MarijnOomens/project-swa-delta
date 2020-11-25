#pragma once
#include <SDL_mixer.h>
#include <SDL.h>
#include <string>

class AudioWrapper
{
public:
	AudioWrapper() {}
	~AudioWrapper() {}

	void playAudio(const std::string& name, bool loop);
};