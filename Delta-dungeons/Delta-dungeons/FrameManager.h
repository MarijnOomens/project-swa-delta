#pragma once
#include "SDL.h"

class FrameManager {
public:
	FrameManager();
	~FrameManager();

	int FPS = 0;
	int frameDelay = 0;
	Uint32 frameStart = 0;
	int frameTime = 0;

	void setFrameStart();
	void setFrameDelay();
private:
};