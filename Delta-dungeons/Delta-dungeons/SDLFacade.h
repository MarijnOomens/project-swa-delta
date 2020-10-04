#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"
#include "DrawController.h"
class SDLFacade {
public:
	SDLFacade();
	~SDLFacade();

	DrawController* drawController;
	SDL_Texture* loadTexture(const char* path);

	void drawTexture(const char* path, Vector2D source2D, Vector2D destination2D);

	void init();
private: 
};