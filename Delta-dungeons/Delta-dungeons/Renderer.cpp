#include "Renderer.h"

SDL_Renderer* Renderer::renderer = nullptr;

SDL_Renderer* Renderer::createRenderer(SDL_Window* window) {
	renderer = SDL_CreateRenderer(window, -1, 0);
	return renderer;
}
