#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
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

	void init(const std::string& title, const int width, const int height, const bool fullscreen);
	void createCamera(const int x, const int y);
	bool checkCameraPosition(const Transform& transform) const;
	std::tuple<int, int> updateCamera(const int playerX, const int playerY);

	void clean() const;
	void pauseGame();
	void quitGame();
	void beforeFrame() const;
	void afterFrame() const;
	void drawTexture(SDL_Texture* texture, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimension, const int row, const int frames, const int speed, const bool animated, const bool flipped, const bool isScreen) const;

private:
	SDL_Window* sdlWindow;
	SDL_Rect camera;
};