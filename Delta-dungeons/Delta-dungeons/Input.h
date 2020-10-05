#pragma once
#include <string>

static class Input {
public:
	Input();

	void parseKeyBindings(std::string string);
	int GetKeyDown();
};