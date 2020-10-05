#pragma once
#include "EngineController.h"

class main {
public:
	main();
	main(EngineController engineController);
private:
	int FPS;
	int frameDelay;
	EngineController engineController;
};