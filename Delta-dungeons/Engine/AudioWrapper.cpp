#include "AudioWrapper.h"

void AudioWrapper::playAudio(const std::string& path, bool loop)
{
	gMusic = Mix_LoadMUS(path.c_str());
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
	else
	{
		Mix_VolumeMusic(25);
		Mix_PlayMusic(gMusic, loop ? -1 : 0);
	}
}

void AudioWrapper::playEffect(const std::string& path)
{
	gEffect = Mix_LoadWAV(path.c_str());
	if (gEffect == NULL)
	{
		printf("Failed to audio effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
	else {
		Mix_PlayChannel(-1, gEffect, 0);
	}
}

