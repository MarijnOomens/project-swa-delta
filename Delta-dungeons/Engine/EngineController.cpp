#include "EngineController.h"
#include "GraphicsComponent.h"
#include <vector>
//Debug
#include "Button.h"
#include "Player.h"
#include "Tile.h"
#include "MainMenu.h"
#include "XMLSceneParser.h"

EngineController::EngineController() {}

EngineController::EngineController(std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects, std::shared_ptr<RenderFacade>renderFacade, std::shared_ptr<AssetManager>assetManager, std::shared_ptr<TextureManager>textureManager)
{
	this->behaviourObjects = behaviourObjects;
	this->renderFacade = renderFacade;
	this->assetManager = assetManager;
	this->textureManager = textureManager;
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	initRenderer("delta dungeons", 1024, 768, false);
	startGame();
}

EngineController::~EngineController() {}

void EngineController::update(std::vector<std::shared_ptr<BehaviourObject>>& bhObjects)
{
	for (auto& bo : bhObjects)
	{
		bo.get()->update();
	}
}

#pragma region Input
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
#pragma endregion Input Handling

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen)
{
	EngineController::renderFacade->init(title, width, height, fullscreen);
}

void EngineController::startGame()
{
	while (renderFacade->renderer->isRunning) {
		/*SDL_Event evt;
		SDL_WaitEvent(&evt);
		if (evt.type == SDL_QUIT)
			renderFacade->renderer.get()->stop();*/

		renderFacade->setFrameStart();
		renderFacade->beforeFrame();

		input.get()->handleInput();

		EngineController::update(behaviourObjects);

		renderFacade->afterFrame();

		// handle input

		//EngineController::Render(gameObjects);
		//loop through draw method

		//change the values 

		renderFacade->setFrameDelay();
	}

	renderFacade->clean();
	std::cout << "Game cleaned" << std::endl;
}