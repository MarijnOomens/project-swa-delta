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
	SDL_Renderer* sdlRenderer;
	SDL_Rect camera;
	SDL_Window* sdlWindow;
	bool isRunning;
	bool isPaused;
	bool isInGame;

	Renderer();
	~Renderer();

	void init(const char* title, const int width, const int height, const bool fullscreen);
	std::tuple<int, int> updateCamera(int playerX, int playerY);
	void createCamera(int x, int y);
	void clean();
	void pauseGame();
	void quitGame();
	void beforeFrame();
	bool checkCameraPosition(const Transform& transform);
	void drawTexture(SDL_Texture* texture, const Transform& transform, const Vector2D& coordinates, const Vector2D& sourceDimension, int row, int frames, int speed, bool animated, bool flipped, bool isScreen);
	void afterFrame();

};