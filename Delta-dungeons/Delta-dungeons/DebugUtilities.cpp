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

void DebugUtilities::toggleShowFPS()
{
	showFPS = !showFPS;
}

bool DebugUtilities::isShowingFPS()
{
	return showFPS;
}

void DebugUtilities::slowDownGame()
{
	engineFacade->slowDownGame();
}

void DebugUtilities::speedUpGame()
{
	engineFacade->speedUpGame();
}

void DebugUtilities::resetSpeedGame()
{
	engineFacade->resetSpeedGame();
}