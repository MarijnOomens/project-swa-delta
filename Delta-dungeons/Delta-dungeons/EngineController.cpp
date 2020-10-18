#include "EngineController.h"
#include "Player.h"

void EngineController::staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	((EngineController*)p)->inputCallbackFunction(keyCode, keyboardEvent);
}

void EngineController::inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	for (auto& gameObject : gameObjects)
	{
		gameObject.get()->handleInput(keyCode, keyboardEvent);
	}
}

EngineController::EngineController() {
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>();
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	gameObjects.emplace_back(std::make_shared<Player>());

	initRenderer("delta dungeons", 800, 600, false);
	startGame();
	//dummy data
}

EngineController::~EngineController() {};

void EngineController::createGameObject() {

};

void EngineController::update(std::list<std::shared_ptr<GameObject>>& gameObjects) {
	for (auto& gameObject : gameObjects)
	{
		gameObject.get()->Update();
	}
};

void EngineController::render(std::list<std::shared_ptr<GameObject>>& gameObjects) {
	renderFacade->render(gameObjects);
};

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen) {
	EngineController::renderFacade->init(title, width, height, fullscreen);
};

void EngineController::startGame() {

	while (renderFacade->renderer->isRunning) {
		renderFacade->setFrameStart();

		// handle input
		input.get()->getKeyPressed();
		input.get()->getKeyReleased();

		//EngineController::Render(gameObjects);
		//loop through draw method

		//change the values 

		renderFacade->setFrameDelay();
	}

	renderFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};
