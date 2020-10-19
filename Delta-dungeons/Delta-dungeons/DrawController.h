#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Renderer.h"
class DrawController {
public:
	DrawController();
	DrawController(std::shared_ptr<Renderer> r);
	~DrawController();
	SDL_Texture* loadTexture(const char* texture);
	void drawTexture(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);
	std::shared_ptr<Renderer> renderer;
};