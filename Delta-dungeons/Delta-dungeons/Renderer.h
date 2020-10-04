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
	static SDL_Rect camera;

	Window* window;

	void stop();
	void clean();
	void updateCamera();
	void render();
	void init(const char* title, int width, int height, bool fullscreen);
private:

};