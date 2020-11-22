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

private:
	SDL_Window* sdlWindow;

	int alphaCounter;
	bool transitioning = false;
};