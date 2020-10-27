#pragma once

#include <string>

static class Sound {
public:
	Sound();
	~Sound();

	void playSound(std::string string);
	void pauseSound(std::string string);
	void stopSound(std::string string);
};