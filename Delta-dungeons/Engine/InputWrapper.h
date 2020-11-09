#pragma once

#include "SDL.h"
#include "Keycodes.h"
#include "Keyboardevent.h"

typedef void(*cbFunction) (void*, KeyCodes, KeyboardEvent);

class InputWrapper {
public:
	cbFunction func;
	SDL_Event event;
	void* pointer;

	InputWrapper();
	InputWrapper(const cbFunction f, void* p);
	~InputWrapper();

	void handleInput(bool isPaused);
	void handleKeyPressed(bool isPaused);
	void handleKeyReleased();
	void mapKeyBindings(const KeyCodes code);
};