#pragma once

#include "SDL.h"
#include "Keycodes.h"
#include "Keyboardevent.h"
#include "Vector2D.h"
#include <iostream>

typedef void(*cbFunction) (void*, KeyCodes, KeyboardEvent, Vector2D);

class InputWrapper 
{
public:
	InputWrapper() {}
	InputWrapper(const cbFunction f, void* p);
	~InputWrapper() {}

	void handleInput(bool isPaused);
	void handleKeyPressed(bool isPaused);
	void handleKeyReleased();
	void handleMouseClicked();
	void mapKeyBindings(const KeyCodes& code);

private:
	cbFunction func = nullptr;
	SDL_Event event = SDL_Event();
	void* pointer = nullptr;
};