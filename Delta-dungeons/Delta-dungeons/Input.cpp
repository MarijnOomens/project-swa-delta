#include "Input.h"
#include <iostream>

Input::Input() {}

Input::Input(const cbFunction f, void* p) :func(f), pointer(p)
{
	facade = std::make_unique<InputFacade>(staticCallbackFunction, this);
}

void Input::staticCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	((Input*)p)->callBackFunction(keyCode, keyboardEvent);
}

void Input::parseKeyBindings(std::string string) {}

void Input::handleInput()
{
	facade->handleInput();
}

void Input::callBackFunction(KeyCodes keyCode, KeyboardEvent keyboardEvent)
{
	func(pointer, keyCode, keyboardEvent);
}