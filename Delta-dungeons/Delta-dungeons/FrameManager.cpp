#include "FrameManager.h"

const int FPS = 60;
const int frameDelay = 1000 / FPS;

Uint32 frameStart;
int frameTime;


void FrameManager::setFrames() {
	frameStart = SDL_GetTicks();

	frameTime = SDL_GetTicks() - frameStart;

	if (frameDelay > frameTime)
	{
		SDL_Delay(frameDelay - frameTime);
	}
}

