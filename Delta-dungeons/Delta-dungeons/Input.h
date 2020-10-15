#pragma once
#include <string>
#include "Keycodes.h"
#include "Keyboardevent.h"
#include "InputFacade.h"

class Input {
public:
	std::unique_ptr<InputFacade> facade;
	Input();
	void parseKeyBindings(std::string string);
	void getKeyPressed();
	void getKeyReleased();
};