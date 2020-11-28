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
		Mix_VolumeMusic(1); //DEBUG PURPOSE REVERT LATER
		Mix_PlayMusic(gMusic, loop ? -1 : 0);
	}
}