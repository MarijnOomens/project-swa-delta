#include "Window.h"



void Window::createWindow(const char* title, int width, int height, bool fullscreen, int flags)
{
	std::cout << "Subsystems initialised!!!" << std::endl;
	sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	if (sdlWindow) {
		std::cout << "Window created!" << std::endl;
	}
}

