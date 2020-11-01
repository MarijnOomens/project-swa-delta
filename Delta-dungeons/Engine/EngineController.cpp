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
	assetManager = std::make_shared<AssetManager>();
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>(renderFacade,assetManager);
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	initRenderer("Delta Dungeons", 1280, 960, false);
}

EngineController::EngineController(std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects, std::shared_ptr<RenderFacade>renderFacade, std::shared_ptr<AssetManager>assetManager, std::shared_ptr<TextureManager>textureManager)
{
	this->behaviourObjects = behaviourObjects;
	this->renderFacade = renderFacade;
	this->assetManager = assetManager;
	this->textureManager = textureManager;
	input = std::make_shared<Input>(staticInputCallbackFunction, this);

	//DEBUG//
	// TILEMAP
	//std::unique_ptr<XMLSceneParser> scene = std::make_unique<XMLSceneParser>();
	//std::vector<std::shared_ptr<Tile>> tiles = scene.get()->loadScene("Assets\\collisionmap.xml");
	//assetManager->addTexture("Level1", "Assets\\Level1_terrain.png");
	//for (std::shared_ptr<Tile> t : tiles)
	//{
	//	std::shared_ptr<GraphicsComponent> gc = std::make_shared<GraphicsComponent>();
	//	gc.get()->addTextureManager(textureManager);
	//	t->addGraphicsComponent(gc, "Level1");
	//	behaviourObjects.emplace_back(gc);
	//	behaviourObjects.emplace_back(t);
	//}

	//// PLAYER
	//assetManager->addTexture("player_anims", "Assets\\player_anims.png");
	//std::shared_ptr<GraphicsComponent> gcPlayer = std::make_shared<GraphicsComponent>();
	//gcPlayer.get()->addTextureManager(textureManager);
	//behaviourObjects.emplace_back(gcPlayer);
	//std::shared_ptr<Player> player = std::make_shared<Player>("player_anims", gcPlayer);
	//behaviourObjects.emplace_back(player);
	//END DEBUG//

	initRenderer("delta dungeons", 1920, 1080, false);
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
#pragma endregion input handling

void EngineController::addTexture(std::string name, std::string path) {
	assetManager->addTexture(name, path);
}
#pragma endregion Input Handling

void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen)
{
	EngineController::renderFacade->init(title, width, height, fullscreen);
}

void EngineController::startGame()
{
	while (renderFacade->renderer->isRunning) {

		renderFacade->setFrameStart();
		renderFacade->beforeFrame();

		input.get()->handleInput();

		EngineController::update(behaviourObjects);

		renderFacade->afterFrame();

		renderFacade->setFrameDelay();
	}

	renderFacade->clean();
	std::cout << "Game cleaned" << std::endl;
};

void EngineController::registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) {
	for (auto& o : objects) 
	{
		if (dynamic_cast<GraphicsComponent*>(o.get()) != nullptr)
		{
			auto ngc = dynamic_cast<GraphicsComponent*>(o.get());
			ngc->addTextureManager(textureManager);
			this->behaviourObjects.emplace_back(ngc);
		}
		else if (dynamic_cast<TextComponent*>(o.get()) != nullptr)
		{
			auto ntc = dynamic_cast<TextComponent*>(o.get());
			ntc->addTextureManager(textureManager);
			this->behaviourObjects.emplace_back(ntc);
		}
		else 
		{
			this->behaviourObjects.emplace_back(o);
		}
	}
}

void EngineController::registerTextures(std::map<std::string, std::string> textures) {
	for (auto& t : textures) {
		assetManager.get()->addTexture(t.first, t.second);
	}
}

void EngineController::registerFonts(std::map<std::string, std::string> fonts) {
	for (auto& t : fonts) {
		assetManager.get()->addFont(t.first, t.second);
	}
}