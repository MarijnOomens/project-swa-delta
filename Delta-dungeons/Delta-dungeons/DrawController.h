#pragma once
#include "SDL.h"
#include "Texture.h"

class DrawController {
public:
	DrawController();
	~DrawController();
	Texture* texture;
	SDL_Texture* loadTexture(const char* texture);
	void drawTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);
private:
};