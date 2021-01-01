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

	void handleInput(const bool isGamePaused, const bool isInputPaused);
	void handleKeyPressed(const bool isGamePaused, const bool isInputPaused);
	void handleKeyReleased(const bool isGamePaused, const bool isInputPaused);
	void handleMouseClicked();
	void mapKeyBindings(const KeyCodes& code);

private:
	void handleMouseMoved();
	cbFunction func = nullptr;
	SDL_Event event = SDL_Event();
	void* pointer = nullptr;
};