#include "AudioUtilities.h"

AudioUtilities AudioUtilities::audioUtilities;

AudioUtilities& AudioUtilities::getInstance()
{
	return audioUtilities;
}

void AudioUtilities::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}

void AudioUtilities::playAudio(const std::string& trackName, bool looped) 
{
	engineFacade->playAudio(trackName, looped);
}

void AudioUtilities::playEffect(const std::string& effectName)
{
	engineFacade->playEffect(effectName);
}
