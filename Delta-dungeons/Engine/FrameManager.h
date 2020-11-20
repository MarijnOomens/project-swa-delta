#pragma once

#include "SDL.h"
#include <iostream>

class FrameManager 
{
public:
	FrameManager();
	~FrameManager() {}

	void setFrameStart();
	void setFrameDelay();
	void slowDownGame();
	void speedUpGame();
	void resetSpeedGame();
	int getFPS() const;

private:
	double fpsLimit;
	double frameDelay;

	Uint32 framesAmount;
	Uint32 startTime;
	Uint32 frameStart;
	double frameTime;

	Uint32 fps;
};