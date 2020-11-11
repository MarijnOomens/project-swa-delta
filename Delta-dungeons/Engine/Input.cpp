#include "Input.h"
#include <iostream>

/// <summary>
/// This class serves as a communication class between InputFacade and EngineController. Input data is received from InputFacade here.
/// </summary>

Input::Input() {}

Input::Input(const cbFunction f, void* p) :func(f), pointer(p)
{
	facade = std::make_unique<InputFacade>(staticCallbackFunction, this);
}

void Input::staticCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	((Input*)p)->callBackFunction(keyCode, keyboardEvent, mousePos);
}

void Input::handleInput(bool isPaused)
{
	facade->handleInput(isPaused);
}

void Input::callBackFunction(KeyCodes keyCode, KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	func(pointer, keyCode, keyboardEvent, mousePos);
}

void Input::parseKeyBindings(std::string string) {}