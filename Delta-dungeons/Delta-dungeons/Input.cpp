#include "Input.h"
#include <iostream>
typedef void(*cbFunction) (Keycodes);

void callbackFunction(const Keycodes code)
{
	std::cout << code + "has been passed to the input class" << std::endl;
}

Input::Input() 
{
	InputFacade facade(callbackFunction);
}

void Input::parseKeyBindings(std::string string) {};

void Input::getKeyDown() 
{ 
};

void Input::getKeyUp()
{
};