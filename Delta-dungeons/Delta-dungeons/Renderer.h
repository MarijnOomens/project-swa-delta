#pragma once
#include "SDL.h"

class Renderer {
public:
	Renderer();
	~Renderer();

	static SDL_Renderer* renderer;

	void init();
	void clean();
private:

};