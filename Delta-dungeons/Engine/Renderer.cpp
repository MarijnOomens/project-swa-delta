#include "Renderer.h"

Renderer::Renderer() {
	camera = { 0, 0, 0, 0 };
};

Renderer::~Renderer() {};

void Renderer::init(const char* title, int width, int height, bool fullscreen) {
	camera = { 0,0, width, height };

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	try {
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
			std::cout << "Subsystems initialised!!!" << std::endl;
			sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
			if (sdlWindow) {
				std::cout << "Window created!" << std::endl;
			}
			else {
				isRunning = false;
				throw("Failed to create window!");
			}
			sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
			if (sdlRenderer)
			{
				SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 255, 255);
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

void Renderer::render(std::vector<std::shared_ptr<GameObject>> gameObjects)
{
	SDL_RenderClear(sdlRenderer);

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
	SDL_RenderPresent(sdlRenderer);
}

void Renderer::updateCamera(int playerX, int playerY)
{

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

void Renderer::clean()
{
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Renderer::stop()
{
	isRunning = false;
}

void Renderer::beforeFrame()
{
	SDL_RenderClear(sdlRenderer);
}

void Renderer::afterFrame()
{
	SDL_RenderPresent(sdlRenderer);
}