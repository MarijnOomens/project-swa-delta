#include "FrameManager.h"

FrameManager::FrameManager() {
	FPS = 60; 
	frameDelay = 1000 / FPS;

	frameStart = 0;
	frameTime = 0;
}
FrameManager::~FrameManager() {};

void FrameManager::setFrameStart() {
	frameStart = SDL_GetTicks();
};

void FrameManager::setFrameDelay() {
	frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
	}
};

