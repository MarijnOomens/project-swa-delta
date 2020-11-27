#pragma once
#include "Audio.h"
#include "AssetManager.h"
#include "AudioFacade.h"
#include <string>
#include <memory>

class Audio {
public:
	Audio(std::shared_ptr<AssetManager> am);
	~Audio() {}

	void playAudio(const std::string& name, bool loop);

private:
	std::shared_ptr<AssetManager> assetManager;
	AudioFacade audioFacade;
};