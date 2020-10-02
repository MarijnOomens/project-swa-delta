#pragma once
#include "SDL.h"
#include <iostream>
#include "Window.h"

class Renderer {
public:
	Renderer();
	~Renderer();

	static SDL_Renderer* renderer;
	static bool isRunning;

	Window* window;

	void stop();
	void clean();
	void init(const char* title, int width, int height, bool fullscreen);
private:

};