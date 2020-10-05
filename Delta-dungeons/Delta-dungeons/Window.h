#pragma once
#include "SDL.h"
#include <iostream>
#include "Renderer.h"
class Window {
public:
	Window();
	~Window();

	SDL_Window* sdlWindow;

	void createWindow(const char* title, int width, int height, bool fullscreen, int flags);

private:
};