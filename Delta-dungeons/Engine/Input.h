#pragma once
#include <string>

#include "Keycodes.h"
#include "Keyboardevent.h"
#include "InputFacade.h"
#include "Vector2D.h"

typedef void(*cbFunction) (void*, KeyCodes, KeyboardEvent, Vector2D);

class Input {
public:
	cbFunction func;
	std::unique_ptr<InputFacade> facade;
	void* pointer;

	Input();
	Input(const cbFunction f, void* p);

	static void staticCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void handleInput(bool isPaused);
	void callBackFunction(KeyCodes keyCode, KeyboardEvent keyboardEvent, Vector2D mousePos);
	void parseKeyBindings(std::string string);
};