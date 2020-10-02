#pragma once
#include "sdl.h"
class Texture {
public:
	Texture();
	~Texture();

	SDL_Texture* LoadTexture(const char* texture);

private:
};