#include "EngineController.h"

EngineController::EngineController() {
	EngineController::sdlFacade = new SDLFacade();
	EngineController::textureManager = new TextureManager();
	//dummy data
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {};
void EngineController::Update(std::list<GameObject> gameObjects) {};
void EngineController::Render(std::list<GameObject> gameObjects) {};

void EngineController::StartGame() {

	while (EngineController::sdlFacade->renderer->isRunning) {
		sdlFacade->setFrameStart();
		
		EngineController::Render(gameObjects);
		EngineController::Update(gameObjects);

		sdlFacade->setFrameDelay();
	}

	sdlFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};
void EngineController::Init() {

};