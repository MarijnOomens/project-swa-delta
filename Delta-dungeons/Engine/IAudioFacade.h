#pragma once
#include <string>
class IAudioFacade
{
public:
	virtual void playAudio(const std::string& path, bool loop) const = 0;
};