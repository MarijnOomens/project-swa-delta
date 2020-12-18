#pragma once

#include "AudioAssetManager.h"
#include "AudioFacade.h"
#include <string>
#include <memory>

class AudioManager {
public:
	AudioManager(std::shared_ptr<AudioAssetManager> aam);
	~AudioManager() {}

	void playAudio(const std::string& name, bool loop);
	void playEffect(const std::string& name);

private:
	std::shared_ptr<AudioAssetManager> audioAssetManager;
	AudioFacade audioFacade;
};