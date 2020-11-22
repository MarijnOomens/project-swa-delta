#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Renderer.h"
#include "Colour.h"
#include <iostream>
#include <map>

class DrawController {
public:
	DrawController() {}
	DrawController(std::shared_ptr<Renderer> renderer);
	~DrawController() {}

	SDL_Texture* loadTexture(const std::string& texture);
	SDL_Texture* loadFont(const std::string& text, const std::string& font, const Colour& colour, int fontSize);
	void drawTexture(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip);
	void drawTexture(SDL_Texture* texture, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimension, int row, int frames, int speed, bool animated, bool flipped, bool isScreen);
	void transition();

private:
	std::shared_ptr<Renderer> renderer;
	std::map<std::string, SDL_Texture*> textures;

	int alphaCounter = 0;
	bool transitioning = false;

};