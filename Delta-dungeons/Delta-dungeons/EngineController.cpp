#include "EngineController.h"
#include "GraphicsComponent.h"
#include <vector>
//Debug
#include "Button.h"
#include "Player.h"
#include "Tile.h"
#include "MainMenu.h"
#include "XMLSceneParser.h"

EngineController::EngineController()
{
	renderFacade = std::make_shared<RenderFacade>();
	assetManager = std::make_shared<AssetManager>();
	textureManager = std::make_shared<TextureManager>(renderFacade, assetManager);
	input = std::make_shared<Input>(staticInputCallbackFunction, this);

	// TILEMAP
	std::unique_ptr<XMLSceneParser> scene = std::make_unique<XMLSceneParser>();
	std::vector<std::shared_ptr<Tile>> tiles = scene.get()->loadScene("Assets\\collisionmap.xml");
	assetManager->addTexture("Level1", "Assets\\Level1_terrain.png");
	for (std::shared_ptr<Tile> t : tiles)
	{
		std::shared_ptr<GraphicsComponent> gc = std::make_shared<GraphicsComponent>();
		gc.get()->addTextureManager(textureManager);
		t->addGraphicsComponent(gc, "Level1");
		behaviourObjects.emplace_back(gc);
		behaviourObjects.emplace_back(t);
	}

	// PLAYER
	assetManager->addTexture("player_anims", "Assets\\player_anims.png");
	std::shared_ptr<GraphicsComponent> gcPlayer = std::make_shared<GraphicsComponent>();
	gcPlayer.get()->addTextureManager(textureManager);
	behaviourObjects.emplace_back(gcPlayer);
	std::shared_ptr<Player> player = std::make_shared<Player>("player_anims", gcPlayer);
	behaviourObjects.emplace_back(player);

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
};

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
};

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
};