#pragma once
#include "IAudioFacade.h"
#include "AudioWrapper.h"
#include <memory>

class AudioFacade : public IAudioFacade
{
public:
	void playAudio(const std::string& path, bool loop) const override;

private:
	std::unique_ptr<AudioWrapper> wrapper;
};