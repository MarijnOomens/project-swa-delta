#pragma once
#include <string>
#include <iostream>
#include "Keycodes.h"
#include "Keyboardevent.h"
#include "InputFacade.h"
#include "Vector2D.h"

typedef void(*cbFunction) (void*, KeyCodes, KeyboardEvent, Vector2D);

class Input 
{
public:
	cbFunction func;
	std::unique_ptr<InputFacade> facade;
	void* pointer;

	Input(const cbFunction f, void* p);

	static void staticCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, const Vector2D mousePos);
	void handleInput(const bool isGamePaused, const bool isInputPaused) const;
	void callBackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, const Vector2D mousePos) const;
	void parseKeyBindings(const std::string& string) const;
};