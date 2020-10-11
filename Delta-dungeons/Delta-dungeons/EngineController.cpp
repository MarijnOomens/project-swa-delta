#include "EngineController.h"

EngineController::EngineController() {
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>();
	//dummy data
}

EngineController::~EngineController() {};

void EngineController::CreateGameObject() {
	
};

void EngineController::Update(std::list<std::shared_ptr<GameObject>>& gameObjects) {
	for(auto& gameObject : gameObjects)
	{
		gameObject.get()->Update();
	}
};

void EngineController::Render(std::list<std::shared_ptr<GameObject>>& gameObjects) {
	sdlFacade->render(gameObjects);
};

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen) {
	EngineController::renderFacade->init(title, width, height, fullscreen);
};

void EngineController::StartGame() {

	while (renderFacade->renderer->isRunning) {
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
