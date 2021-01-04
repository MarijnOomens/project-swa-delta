#pragma once
#include <memory>
#include "EngineFacade.h"

class AudioUtilities
{
public:
	static AudioUtilities& getInstance();
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);
	void playAudio(const std::string& trackName, bool looped);
	void playEffect(const std::string& effectName);
private:
	static AudioUtilities audioUtilities;
	std::shared_ptr<EngineFacade> engineFacade;
};

