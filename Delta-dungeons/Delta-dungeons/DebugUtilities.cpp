#include "DebugUtilities.h"

DebugUtilities DebugUtilities::debugUtilities;

DebugUtilities& DebugUtilities::getInstance()
{
	return debugUtilities;
}

int DebugUtilities::getFPS() 
{
	return engineFacade->getFPS();
}

void DebugUtilities::setEngineFacade(std::shared_ptr<EngineFacade> engineFacade)
{
	this->engineFacade = engineFacade;
}