#include "EngineController.h"
#include <vector>
#include "GraphicsComponent.h"
#include "Button.h"
#include "Player.h"


EngineController::EngineController() {
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>(renderFacade);
	assetManager = std::make_shared<AssetManager>();
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	

	GraphicsComponent* gc1 = new GraphicsComponent();
	Player* player = new Player();
	
	behaviourObjects.emplace_back(player);

	initRenderer("delta dungeons", 800, 600, false);
	startGame();
}

EngineController::~EngineController() {};

#pragma region input
// Get callback from Input
void EngineController::staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	((EngineController*)p)->inputCallbackFunction(keyCode, keyboardEvent);
}

// Handle callback from staticInputCallbackFunction
void EngineController::inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent)
{
	for (auto& gameObject : behaviourObjects)
	{
		gameObject.get()->handleInput(keyCode, keyboardEvent);
	}
}
#pragma endregion input handling

void EngineController::createGameObject() {

};

void EngineController::Update(std::list<std::shared_ptr<BehaviourObject>>& bhObjects) {
	for(auto& bo : bhObjects)
	{
		bo.get()->Update();
	}
};

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen) {
	EngineController::renderFacade->init(title, width, height, fullscreen);
};

void EngineController::startGame() {

	while (renderFacade->renderer->isRunning) {

		/*SDL_Event evt;
		SDL_WaitEvent(&evt);
		if (evt.type == SDL_QUIT) 
			renderFacade->renderer.get()->stop();*/

		renderFacade->setFrameStart();
		renderFacade->beforeFrame();

		EngineController::Update(behaviourObjects);
		
		renderFacade->afterFrame();

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
