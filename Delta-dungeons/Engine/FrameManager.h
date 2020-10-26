#pragma once

#include "SDL.h"

class FrameManager {
public:
	FrameManager();
	~FrameManager();

	int FPS;
	int frameDelay;
	Uint32 frameStart;
	int frameTime;

	void setFrameStart();
	void setFrameDelay();
private:
};