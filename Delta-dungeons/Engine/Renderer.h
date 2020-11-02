#pragma once

#include "SDL.h"
#include "GameObject.h"
#include <iostream>
#include <list>
#include <memory>
#include <tuple>

class Renderer {
public:
	SDL_Renderer* sdlRenderer;
	SDL_Rect camera = { 0, 0, 0, 0 };
	SDL_Window* sdlWindow;
	bool isRunning;

	Renderer();
	~Renderer();

	void init(const char* title, const int width, const int height, const bool fullscreen);
	void render(std::vector<std::shared_ptr<GameObject>> value);
	std::tuple<int, int> updateCamera(int playerX, int playerY);
	void clean();
	void stop();
	void beforeFrame();
	void afterFrame();
};