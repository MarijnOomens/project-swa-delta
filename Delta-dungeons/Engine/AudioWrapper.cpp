#include "AudioWrapper.h"

void AudioWrapper::playAudio(const std::string& path, bool loop)
{
	Mix_Music* gMusic = Mix_LoadMUS(path.c_str());
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	else
	{
		if (Mix_PlayingMusic() == 0)
		{
			Mix_PlayMusic(gMusic, loop ? -1 : 0);
		}
	}
}