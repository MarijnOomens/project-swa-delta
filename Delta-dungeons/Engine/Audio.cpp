#include "Audio.h"

Audio::Audio(std::shared_ptr<AssetManager> am) : assetManager(am) {}

void Audio::playAudio(const std::string& name, bool loop)
{
	audioFacade.playAudio(assetManager->getAudio(name), loop);
}
