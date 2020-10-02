#include "Renderer.h"

SDL_Renderer* Renderer::renderer = nullptr;

bool Renderer::isRunning = false;



void Renderer::init(const char* title, int width, int height, bool fullscreen) {

	Renderer::window = new Window();
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems initialised!!!" << std::endl;
		Renderer::window->createWindow(title, width, height, fullscreen, flags);

		Renderer::renderer = SDL_CreateRenderer(Window::sdlWindow, -1, 0);
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

void Renderer::stop() {
	isRunning = false;
}


void Renderer::clean() {
	SDL_DestroyWindow(Window::sdlWindow);
	SDL_DestroyRenderer(Renderer::renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}