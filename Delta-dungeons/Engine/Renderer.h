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
	SDL_Renderer* sdlRenderer;

	Renderer();
	~Renderer();

	void init(const std::string& title, int width, int height, bool fullscreen);

	void createCamera(int x, int y);
	bool checkCameraPosition(const Transform& transform) const;
	std::tuple<int, int> updateCamera(int playerX, int playerY);

	void clean() const;
	void pauseGame();
	void quitGame();
	void beforeFrame() const;
	void afterFrame() const;
	void drawTexture(SDL_Texture* texture, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimension, int row, int frames, int speed, bool animated, bool flipped, bool isScreen) const;

private:
	SDL_Window* sdlWindow;
	SDL_Rect camera;
};