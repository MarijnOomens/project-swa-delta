#pragma once
#include <string>

#include "Keycodes.h"
#include "Keyboardevent.h"
#include "InputFacade.h"

typedef void(*cbFunction) (void*, KeyCodes, KeyboardEvent);

class Input {
public:
	cbFunction func;
	void* pointer;
	std::unique_ptr<InputFacade> facade;

	Input();
	Input(const cbFunction f, void* p);

	static void staticCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent);
	void parseKeyBindings(std::string string);
	void handleInput();
	void callBackFunction(KeyCodes keyCode, KeyboardEvent keyboardEvent);
};