#pragma once
#include "SDL.h"
#include "Keycodes.h"
#include "Keyboardevent.h"


typedef void(*cbFunction) (void*, KeyCodes, KeyboardEvent);

class InputWrapper {
public:
	cbFunction func;
	void* pointer;

	InputWrapper();
	InputWrapper(const cbFunction f, void *p);
	~InputWrapper();

	SDL_Event event;

	void handleInput();
	void handleKeyReleased();
	void mapKeyBindings(const KeyCodes code);
	void handleKeyPressed();

};