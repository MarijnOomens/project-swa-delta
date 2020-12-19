#pragma once
#include "SDL_mixer.h"
#include "SDL.h"
#include <string>

class AudioWrapper
{
public:
	AudioWrapper() {}
	~AudioWrapper() {}

	void playAudio(const std::string& path, bool loop);
	void playEffect(const std::string& path);
private:
	Mix_Music* gMusic = NULL;
	Mix_Chunk* gEffect = NULL;
};