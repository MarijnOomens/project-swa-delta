#include "EngineController.h"

/// <summary>
/// This class has the responsibility of managing different classes in the engine. It communicaties with classes like TextureManager and RenderFacade.
/// </summary>
EngineController::EngineController() 
{
	assetManager = std::make_shared<AssetManager>();
	renderFacade = std::make_shared<RenderFacade>();
	textureManager = std::make_shared<TextureManager>(renderFacade,assetManager);
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	initRenderer("Delta Dungeons", 1280, 960, false);
}

EngineController::~EngineController() {}

/// <summary>
/// This method keeps executing while the gaming is running. It keeps updating all behaviour objects.
/// </summary>
/// <param name="bhObjects">Vector of all available behaviour objects.</param>
void EngineController::update(std::vector<std::shared_ptr<BehaviourObject>>& bhObjects)
{
	for (auto& bo : bhObjects)
	{
		bo.get()->update();
	}
}


/// <summary>
/// Receives input data from the class Input and passes it to a new function.
/// </summary>
/// <param name="p">Void pointer.</param>
/// <param name="keyCode">The key that is read, like 'W'.</param>
/// <param name="keyboardEvent">The key that is read, like 'W'.</param>
void EngineController::staticInputCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	((EngineController*)p)->inputCallbackFunction(keyCode, keyboardEvent, mousePos);
}

/// <summary>
/// Calls the handleInput function for each game object.
/// </summary>
/// <param name="keyCode">The key that is read, like 'W'.</param>
/// <param name="keyboardEvent">The key that is read, like 'W'.</param>
void EngineController::inputCallbackFunction(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	isSceneSwitched = false;
	if (keyCode == KeyCodes::KEY_ESC) 
	{
		quitGame();
	}
	else if (keyCode == KeyCodes::KEY_P)
	{
		renderFacade.get()->pauseGame();
		pauseScreen();
	}
	else {
		for (auto& gameObject : behaviourObjects)
		{
			if (!isSceneSwitched) {
				gameObject.get()->handleInput(keyCode, keyboardEvent, mousePos);
			}
		}
	}
}
#pragma endregion Input handling

/// <summary>
/// This method adds a texture to the AssetManager so that the texture is a known asset.
/// </summary>
/// <param name="name">Texture name.</param>
/// <param name="path">Texture path.</param>
void EngineController::addTexture(std::string name, std::string path) {
	assetManager->addTexture(name, path);
}

/// <summary>
/// This method calls an initialization function in RenderFacade with the given data, like resolution of the game window.
/// </summary>
/// <param name="title">Title of game window.</param>
/// <param name="width">Width of game window.</param>
/// <param name="height">Height of game window.</param>
/// <param name="fullscreen">Boolean whether game is fullscreen or not.</param>
void EngineController::initRenderer(const char* title, int width, int height, bool fullscreen)
{
	EngineController::renderFacade->init(title, width, height, fullscreen);
}

void EngineController::createCamera(int x, int y)
{
	renderFacade->createCamera(x,y);
}

/// <summary>
/// This method contains the game loop from which a few functions that need constant updating, are executed.
/// </summary>
void EngineController::startGame()
{
	while (renderFacade->renderer->isRunning) {

		renderFacade->setFrameStart();

		input.get()->handleInput(renderFacade->renderer->isPaused);
		if (!renderFacade->renderer->isPaused) 
		{
			renderFacade->beforeFrame();
			EngineController::update(behaviourObjects);
		}
		renderFacade->afterFrame();
		renderFacade->setFrameDelay();
	}
}

void EngineController::registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
{
	std::vector<std::shared_ptr<BehaviourObject>> tempObjects;
	for (auto& o : behaviourObjects)
	{
		if (dynamic_cast<GraphicsComponent*>(o.get()) != nullptr)
		{
			auto ngc = dynamic_cast<GraphicsComponent*>(o.get());
			ngc->addTextureManager(textureManager);		
			tempObjects.emplace_back(ngc);
		}
		else if (dynamic_cast<TextComponent*>(o.get()) != nullptr)
		{
			auto ntc = dynamic_cast<TextComponent*>(o.get());
			ntc->addTextureManager(textureManager);
			tempObjects.emplace_back(ntc);
		}
		else
		{
			tempObjects.emplace_back(o);
		}
	}

	sceneManager.registerScene(sceneName, tempObjects);
}

void EngineController::loadScene(std::string sceneName, std::string fromScene, bool clearPrevious)
{
	isSceneSwitched = true;
	behaviourObjects = sceneManager.loadScene(sceneName, fromScene, clearPrevious);
}

void EngineController::loadPreviousScene()
{
	isSceneSwitched = true;
	behaviourObjects = sceneManager.loadPreviousScene();
	update(behaviourObjects);
}

void EngineController::addOverlayScene(const std::string& sceneName)
{
	isSceneSwitched = true;
	auto tempObjects = sceneManager.addOverlayScene(sceneName);
	behaviourObjects.insert(behaviourObjects.end(), tempObjects.begin(), tempObjects.end());
	update(behaviourObjects);
}

void EngineController::passPlayerPosition(int x, int y)
{
	std::tuple<int, int> positions = renderFacade->passPlayerPosition(x, y);
}

/// <summary>
/// This method registers all given textures, in the AssetManager.
/// </summary>
/// <param name="textures">Map of multiple textures.</param>
void EngineController::registerTextures(std::map<std::string, std::string> textures) {
	for (auto& t : textures) {
		assetManager.get()->addTexture(t.first, t.second);
	}
}

/// <summary>
/// This method registers all given fonts, in the AssetManager.
/// </summary>
/// <param name="fonts">Map of multiple fonts.</param>
void EngineController::registerFonts(std::map<std::string, std::string> fonts) {
	for (auto& t : fonts) {
		assetManager.get()->addFont(t.first, t.second);
	}
}

void EngineController::pauseScreen()
{
	if (renderFacade->renderer->isPaused) 
	{
		addOverlayScene("PauseScreen");
		EngineController::update(behaviourObjects);
	}
	else 
	{
		loadPreviousScene();
	}
}

void EngineController::quitGame() 
{
	renderFacade.get()->quitGame();
}

int EngineController::getFPS()
{
	return renderFacade->getFPS();
}

void EngineController::slowDownGame()
{
	renderFacade.get()->slowDownGame();
}

void EngineController::speedUpGame()
{
	renderFacade.get()->speedUpGame();
}

void EngineController::resetSpeedGame()
{
	renderFacade.get()->resetSpeedGame();
}