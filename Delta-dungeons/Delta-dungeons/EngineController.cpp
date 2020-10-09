#include "EngineController.h"

EngineController::EngineController() {
	sdlFacade = std::make_shared<SDLFacade>();
	textureManager = std::make_shared<TextureManager>();
	//dummy data
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {
	
};
void EngineController::Update(std::list<GameObject> gameObjects) {
	for(auto &gameObject : gameObjects)
	{
		gameObject.Update();
	}
};
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
