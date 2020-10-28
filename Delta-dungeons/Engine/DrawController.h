#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Renderer.h"
#include <iostream>
#include <map>

class DrawController {
public:
	std::shared_ptr<Renderer> renderer;
	std::map<std::string, SDL_Texture*> textures;

	DrawController();
	DrawController(std::shared_ptr<Renderer> r);
	~DrawController();

	SDL_Texture* loadTexture(std::string texture);
	void drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, int frames, int speed, bool animated, SDL_RendererFlip flip);
};