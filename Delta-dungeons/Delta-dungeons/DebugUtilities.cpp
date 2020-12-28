#include "DebugUtilities.h"

DebugUtilities DebugUtilities::debugUtilities;

DebugUtilities& DebugUtilities::getInstance()
{
	return debugUtilities;
}

int DebugUtilities::getFPS()const
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

void DebugUtilities::slowDownGame()const
{
	engineFacade->slowDownGame();
}

void DebugUtilities::speedUpGame()const
{
	engineFacade->speedUpGame();
}

void DebugUtilities::resetSpeedGame()const
{
	engineFacade->resetSpeedGame();
}

void DebugUtilities::pauseGame()const
{
	engineFacade->pauseGame();
}

void DebugUtilities::pauseInput()const
{
	engineFacade->pauseInput();
}

void DebugUtilities::toggleCheatCollision()
{
	cheatCollision = !cheatCollision;
}

bool DebugUtilities::isCheatCollisionOn()
{
	return cheatCollision;
}
