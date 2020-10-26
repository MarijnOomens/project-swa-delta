#pragma once
#include <string>


static class Sound {
public:
	Sound();
	~Sound();
	void PlaySound(std::string string);
	void PauseSound(std::string string);
	void StopSound(std::string string);
};