#pragma once
#include <string>

static class Input {
public:
	void parseKeyBindings(std::string string);
	int GetKeyDown();
};