#include "Renderer.h"

SDL_Renderer* Renderer::renderer = nullptr;

bool Renderer::isRunning = false;



void Renderer::init(const char* title, int width, int height, bool fullscreen) {
	Renderer::camera = { 0,0, width, height };
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

void Renderer::updateCamera() {

	//update gameobjects positioning based on camera x and y

	//camera.x = player.position.x - 400;
	//camera.y = player.position.y - 320;

	if (Renderer::camera.x < 0) {
		Renderer::camera.x = 0;
	}
	if (Renderer::camera.y < 0) {
		Renderer::camera.y = 0;
	}
	if (Renderer::camera.x > camera.w) {
		Renderer::camera.x = camera.w;
	}

	if (Renderer::camera.y > camera.h) {
		Renderer::camera.y = camera.h;
	}
}

void Renderer::render() {
	SDL_RenderClear(Renderer::renderer);

	//call SDL_RenderCopyEx() for every gameobject
	//for (auto& t : gameobjects)
	//{
	//	t->DrawTexture(); 
	//}
	SDL_RenderPresent(renderer);
}

void Renderer::clean() {
	SDL_DestroyWindow(Window::sdlWindow);
	SDL_DestroyRenderer(Renderer::renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}