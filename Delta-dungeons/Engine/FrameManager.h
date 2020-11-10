#pragma once

#include "SDL.h"

class FrameManager {
public:
	int FPS;
	int frameDelay;
	int frameTime;
	Uint32 frameStart;

	FrameManager();
	~FrameManager();

	void setFrameStart();
	void setFrameDelay();
	int getFPS();
	void slowDownGame();
	void speedUpGame();
	void resetSpeedGame();
private:
	Uint32 frames = 0;
	Uint32 startTime;
	Uint32 fps;
};