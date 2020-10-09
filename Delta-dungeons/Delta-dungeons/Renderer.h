#pragma once
#include "SDL.h"
#include <iostream>
#include <list>
#include "GameObject.h"
class Renderer {
public:
	Renderer();
	~Renderer();

	static SDL_Renderer* renderer;
	static bool isRunning;
	SDL_Rect camera = { 0, 0, 0, 0 };

	SDL_Window* sdlWindow;

	void stop();
	void clean();
	void updateCamera();
	void render(std::list<GameObject> value);
	void init(const char* title, const int width, const int height, const bool fullscreen);
private:

};