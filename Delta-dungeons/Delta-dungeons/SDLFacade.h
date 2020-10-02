#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "Vector2D.h"

class SDLFacade {
public:
	SDLFacade();
	~SDLFacade();

	SDL_Texture loadTexture(std::string path);

	void rawTexture(Vector2D source2D, Vector2D destination2D);

	void init();
private: 
};