#pragma once
#include "SDL.h"
class InputWrapper {
public:
	InputWrapper();
	~InputWrapper();

	SDL_Event event;
	void handleEvents();

private:
};