#pragma once
#include <string>
#include "Keycodes.h"
#include "InputFacade.h"

class Input {
public:
	std::unique_ptr<InputFacade> facade;
	Input();
	void parseKeyBindings(std::string string);
	void getKeyDown();
	void getKeyUp();
};