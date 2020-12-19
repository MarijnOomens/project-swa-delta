#include "AudioManager.h"

AudioManager::AudioManager(std::shared_ptr<AudioAssetManager> aam) : audioAssetManager(aam) {}

void AudioManager::playAudio(const std::string& name, bool loop)
{
	audioFacade.playAudio(audioAssetManager->getAsset(name), loop);
}