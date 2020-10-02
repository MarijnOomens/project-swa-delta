#pragma once
#include "SDL.h"

class DrawController {
public:
	DrawController();
	~DrawController();

	SDL_Texture loadTexture();

	void drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination);

	void init();
private:
};