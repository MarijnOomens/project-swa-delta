#pragma once
#include "SDL.h"
#include "Keycodes.h"
#include "Keyboardevent.h"

typedef void (*cbFunction) (KeyCodes, KeyboardEvent);

class InputWrapper {
public:
	cbFunction func;

	InputWrapper();
	InputWrapper(const cbFunction f);
	~InputWrapper();

	SDL_Event event;

	void handleKeyPressed();
	void handleKeyReleased();
	void mapKeyBindings(const KeyCodes code);

};