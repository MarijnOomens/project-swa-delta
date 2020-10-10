#pragma once
#include "SDL.h"
#include "Keycodes.h"
typedef void (*cbFunction) (Keycodes);

class InputWrapper {
public:
	cbFunction func;

	InputWrapper();
	InputWrapper(const cbFunction f);
	~InputWrapper();

	SDL_Event event;

	void handleEvents();
	void mapKeyBindings(const Keycodes code);

};