#include "Input.h"
#include <iostream>
typedef void(*cbFunction) (Keycodes);

void callbackFunction(const Keycodes code)
{
	//std::cout << code + "has been passed to the input class" << std::endl;
}

Input::Input()
{
	facade = std::make_unique<InputFacade>(callbackFunction);
}

void Input::parseKeyBindings(std::string string) {};

void Input::getKeyDown()
{
	facade->handleEvents();
};

void Input::getKeyUp()
{
};