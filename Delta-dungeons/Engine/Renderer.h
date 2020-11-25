#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "SDL_ttf.h"
#include <iostream>
#include <list>
#include <memory>
#include <tuple>

class Renderer {
public:
	bool isRunning;
	bool isPaused;
	bool transitioning = false;
	SDL_Renderer* sdlRenderer;
	SDL_Rect camera;

	Renderer();
	~Renderer();

	void init(const std::string& title, const int width, const int height, const bool fullscreen);
	void createCamera(const int x, const int y);
	bool checkCameraPosition(const Transform& transform) const;
	std::tuple<int, int> updateCamera(const int playerX,const int playerY);

	void clean() const;
	void pauseGame();
	void quitGame();
	void beforeFrame() const;
	void afterFrame() const;
	void drawTexture(SDL_Texture* texture, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimension, int row, int frames, int speed, bool animated, bool flipped, bool isScreen);
	void drawText(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination, SDL_RendererFlip flip);
	void transition();
	void checkTransition();

private:
	SDL_Window* sdlWindow;

	int alphaCounter;
};