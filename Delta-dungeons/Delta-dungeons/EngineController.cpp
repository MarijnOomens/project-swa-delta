#include "EngineController.h"

EngineController::EngineController() {
	EngineController::sdlFacade = new SDLFacade();
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {};
void EngineController::Update(GameObject gameObjects) {};
void EngineController::Render(std::list<GameObject> gameObjects) {};
void EngineController::Init() {};