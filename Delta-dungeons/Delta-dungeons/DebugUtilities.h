#pragma once
#include "EngineFacade.h"

class DebugUtilities
{
public:
	static DebugUtilities& getInstance();
	int getFPS();
	void setEngineFacade(std::shared_ptr<EngineFacade> engineFacade);
	void toggleShowFPS();
	bool isShowingFPS();
	void slowDownGame();
	void speedUpGame();
	void resetSpeedGame();

private:
	static DebugUtilities debugUtilities;

	std::shared_ptr<EngineFacade> engineFacade;
	DebugUtilities() {}
	bool showFPS = false;
};

