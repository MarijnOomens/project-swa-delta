#include "Window.h"

bool Window::isRunning = false;


void Window::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialised!!!" << std::endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		Renderer::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Renderer::renderer)
		{
			SDL_SetRenderDrawColor(Renderer::renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
}

void Window::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(Renderer::renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Window::handleEvents() {
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}