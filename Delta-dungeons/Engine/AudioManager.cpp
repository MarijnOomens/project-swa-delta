#include "AudioManager.h"

AudioManager::AudioManager(std::shared_ptr<AudioAssetManager> aam) : audioAssetManager(aam) {}

void AudioManager::playAudio(const std::string& name, bool loop)
{
	audioFacade.playAudio(audioAssetManager->getAsset(name), loop);
}

void AudioManager::playEffect(const std::string& name)
{
	audioFacade.playEffect(audioAssetManager->getAsset(name));
}
