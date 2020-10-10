#include "EngineController.h"

EngineController::EngineController() {
	renderFacade = std::make_shared<RenderFacade>();
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
	renderFacade->render(gameObjects);
};

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen) {
	EngineController::renderFacade->initRenderer(title, width, height, fullscreen);
};

void EngineController::StartGame() {

	while (EngineController::renderFacade->renderer->isRunning) {
		renderFacade->setFrameStart();
		
		EngineController::Render(gameObjects);
		//loop through draw method

		EngineController::Update(gameObjects);
		//change the values 
		renderFacade->setFrameDelay();
	}

	renderFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};
