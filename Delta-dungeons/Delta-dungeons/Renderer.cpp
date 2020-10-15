#include "Renderer.h"

Renderer::Renderer() {
	camera = { 0, 0, 0, 0 };
	sdlWindow = nullptr;
};
Renderer::~Renderer() {};

SDL_Renderer* Renderer::renderer = nullptr;

bool Renderer::isRunning = false;

void Renderer::init(const char* title, int width, int height, bool fullscreen) {
	Renderer::camera = { 0,0, width, height };

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
			std::cout << "Subsystems initialised!!!" << std::endl;
			Renderer::sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
			if (Renderer::sdlWindow) {
				std::cout << "Window created!" << std::endl;
			}
			else {
				isRunning = false;
				throw("Failed to create window!");
			}
			Renderer::renderer = SDL_CreateRenderer(Renderer::sdlWindow, -1, 0);
			if (Renderer::renderer)
			{
				SDL_SetRenderDrawColor(Renderer::renderer, 255, 255, 255, 255);
				std::cout << "Renderer created!" << std::endl;
			}
			else {
				isRunning = false;
				throw("Failed to create Render!");
			}
			isRunning = true;
		}
		else {
			throw("Subsystems are not initialised!");
			isRunning = false;
		}
		std::cout << "Image is loaded and created!" << std::endl;
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
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

void Renderer::render(std::list<std::shared_ptr<GameObject>> gameObjects) {
	SDL_RenderClear(Renderer::renderer);

	try {
		if (gameObjects.empty()) {
			throw("There are no gameobjects to render!");
		}
		else {
			for (auto& t : gameObjects)
			{
				// TODO: Render all GraphicsComponents instead of GameObjects
			}
		}
	}
	catch (std::string error) {
		std::cout << "Error: " << error << std::endl;
	}
	//call SDL_RenderCopyEx() for every gameobject
	SDL_RenderPresent(Renderer::renderer);
}

void Renderer::clean() {
	SDL_DestroyWindow(Renderer::sdlWindow);
	SDL_DestroyRenderer(Renderer::renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Renderer::beforeFrame() {
	SDL_RenderClear(Renderer::renderer);
}

void Renderer::afterFrame() {
	SDL_RenderPresent(Renderer::renderer);
}

//graph->texturemaanger->facade