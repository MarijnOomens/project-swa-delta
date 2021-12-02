#include "FrameManager.h"

/// <summary>
/// The FrameManager makes sure the game runs at a max 60FPS to limit the memory usage.
/// </summary>
FrameManager::FrameManager()
{
	fpsLimit = 144.0;
	frameDelay = 1000.0 / fpsLimit;

	framesAmount = 0;
	startTime = SDL_GetTicks();
	frameStart = 0;
	frameTime = 0;

	fps = 0;
}

/// <summary>
/// setFrameStart is used to get the start of the second, to determine later if a delay needs to be called to stay 60FPS
/// </summary>
void FrameManager::setFrameStart()
{
	frameStart = SDL_GetTicks();
}

Uint32 FrameManager::getFrameStart()
{
	return frameStart;
}

/// <summary>
/// setFrameDelay is used if the FPS is higher than 60. This will put it back down to 60 and limit the redraws.
/// </summary>
void FrameManager::setFrameDelay()
{
	framesAmount++;
	if (startTime < SDL_GetTicks() - 1000)
	{
		startTime = SDL_GetTicks();
		fps = framesAmount - 1;
		framesAmount = 0;
	}

	frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime) {
		SDL_Delay(static_cast<Uint32>(frameDelay - frameTime));
	}
}

void FrameManager::slowDownGame()
{
	if (fpsLimit > 3.0)
	{
		fpsLimit = fpsLimit * 0.9;
	}
	else 
	{
		fpsLimit = 3.0;
	}
	frameDelay = 1000.0 / fpsLimit;
}

void FrameManager::speedUpGame()
{
	if (fpsLimit < 144.0)
	{
		fpsLimit = fpsLimit * 1.1;
	}
	else 
	{
		fpsLimit = 144.0;
	}
	frameDelay = 1000.0 / fpsLimit;
}

void FrameManager::resetSpeedGame()
{
	fpsLimit = 60.0;
	frameDelay = 1000.0 / fpsLimit;
}

int FrameManager::getFPS() const
{
	return fps;
}