#pragma once
#include "SDL.h"
#include <iostream>
#include <list>
#include "GameObject.h"
#include <memory>

class Renderer {
public:
	Renderer();
	~Renderer();

	SDL_Renderer* sdlRenderer;
	bool isRunning;
	SDL_Rect camera = { 0, 0, 0, 0 };

	SDL_Window* sdlWindow;

	void stop();
	void clean();
	void updateCamera();
	void render(std::vector<std::shared_ptr<GameObject>> value);
	void init(const char* title, const int width, const int height, const bool fullscreen);
	void beforeFrame();
	void afterFrame();
private:

};