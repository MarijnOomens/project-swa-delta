#pragma once
#include "SDL.h"

class FrameManager {
public:
	FrameManager();
	~FrameManager();

	const int FPS;
	const int frameDelay;
	Uint32 frameStart;
	int frameTime;

	void setFrames();
private:
};