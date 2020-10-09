#pragma once
#include <string>
#include "Keycodes.h"
#include "InputFacade.h"

static class Input {
public:

	Input();
	void parseKeyBindings(std::string string);
	void getKeyDown();
};