#include "FrameManager.h"

/// <summary>
/// The FrameManager makes sure the game runs at a max 60FPS to limit the memory usage.
/// </summary>
FrameManager::FrameManager()
{
	FPS = 60;
	frameDelay = 1000 / FPS;

	frameStart = 0;
	frameTime = 0;

	startTime = SDL_GetTicks();
}

FrameManager::~FrameManager() {}

/// <summary>
/// setFrameStart is used to get the start of the second, to determine later if a delay needs to be called to stay 60FPS
/// </summary>
void FrameManager::setFrameStart()
{
	frameStart = SDL_GetTicks();
}

/// <summary>
/// setFrameDelay is used if the FPS is higher than 60. This will put it back down to 60 and limit the redraws.
/// </summary>
void FrameManager::setFrameDelay()
{
	//++framesAmount;
	frameTime = SDL_GetTicks() - frameStart;
	//if (frameTime)
	//{
	//	double time = frameTime;
	//	double averageFPS = framesAmount / time;
	//}
	if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
	}
}

int FrameManager::getFPS() 
{
	return 60;
}