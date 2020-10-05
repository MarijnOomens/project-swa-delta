#pragma once
#include "SDL.h"
#include <iostream>
class Renderer {
public:
	Renderer();
	~Renderer();

	static SDL_Renderer* renderer;
	static bool isRunning;
	SDL_Rect camera;

	SDL_Window* sdlWindow;

	void stop();
	void clean();
	void updateCamera();
	void render();
	void init(const char* title, int width, int height, bool fullscreen);
private:

};