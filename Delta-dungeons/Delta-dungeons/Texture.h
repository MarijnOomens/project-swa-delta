#pragma once
#include "sdl.h"
#include "SDL_image.h"

class Texture {
public:
	Texture();
	~Texture();

	SDL_Texture* LoadTexture(const char* texture);

private:
};