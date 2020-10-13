#include "FrameManager.h"

FrameManager::FrameManager() {
	FPS = 60; 
	frameDelay = 60 / 1000;
}
FrameManager::~FrameManager() {};

Uint32 frameStart = 0;
int frameTime = 0;

void FrameManager::setFrameStart() {
	frameStart = SDL_GetTicks();
};

void FrameManager::setFrameDelay() {
	frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
	}
};

