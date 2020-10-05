#include "EngineController.h"

EngineController::EngineController() {
	EngineController::sdlFacade = new SDLFacade();
	EngineController::textureManager = new TextureManager();
	//dummy data
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {};
void EngineController::Update(std::list<GameObject> gameObjects) {};
void EngineController::Render(std::list<GameObject> gameObjects) {
	sdlFacade->render(gameObjects);
};

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen) {
	EngineController::sdlFacade->initRenderer(title, width, height, fullscreen);
};

void EngineController::StartGame() {

	while (EngineController::sdlFacade->renderer->isRunning) {
		sdlFacade->setFrameStart();
		
		EngineController::Render(gameObjects);
		//loop through draw method

		EngineController::Update(gameObjects);
		//change the values 
		sdlFacade->setFrameDelay();
	}

	sdlFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};
