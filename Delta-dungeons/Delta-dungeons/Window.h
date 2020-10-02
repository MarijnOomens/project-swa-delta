#pragma once
#include "SDL.h"
#include <iostream>
#include "Renderer.h"

class Window {
public:
	Window();
	~Window();

	SDL_Window* window;
	static SDL_Event event;
	static bool isRunning;


	void init(const char* title, int width, int height, bool fullscreen);
	void clean();
	void handleEvents();
private:
};