#include "EngineController.h"

EngineController::EngineController() {
	EngineController::sdlFacade = new SDLFacade();
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {};
void EngineController::Update(GameObject& gameObjects) {};
void EngineController::Render(std::list<std::unique_ptr<GameObject>> gameObjects) {};
void EngineController::Init() {};