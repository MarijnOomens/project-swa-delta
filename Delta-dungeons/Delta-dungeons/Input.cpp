#include "Input.h"
#include <iostream>

void callbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	std::cout << "Code: " + std::to_string(keyCode) << " and KeyboardEvent: " + std::to_string(keyboardEvent) << std::endl;
}

Input::Input()
{
	facade = std::make_unique<InputFacade>(callbackFunction);
}

void Input::parseKeyBindings(std::string string) {};

void Input::getKeyPressed()
{
	facade->handleKeyPressed();
};

void Input::getKeyReleased()
{
	facade->handleKeyReleased();
};