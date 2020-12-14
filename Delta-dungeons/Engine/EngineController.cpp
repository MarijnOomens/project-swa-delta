#include "EngineController.h"

/// <summary>
/// This class has the responsibility of managing different classes in the engine. It communicaties with classes like TextureManager and RenderFacade.
/// </summary>
EngineController::EngineController(const std::string& title, int screenWidth, int screenHeight, bool fullScreen)
{
	collision = std::make_shared<Collision>();
	textureAssetManager = std::make_shared<TextureAssetManager>();
	fontAssetManager = std::make_shared<FontAssetManager>();
	audioAssetManager = std::make_shared<AudioAssetManager>();

	renderFacade = std::make_shared<RenderFacade>(staticPassCameraDimensionFunction, this);
	textureManager = std::make_shared<TextureManager>(renderFacade, textureAssetManager);
	input = std::make_shared<Input>(staticInputCallbackFunction, this);
	fontManager = std::make_shared<FontManager>(renderFacade, fontAssetManager);
	audioManager = std::make_unique<AudioManager>(audioAssetManager);

	initRenderer(title, screenWidth, screenHeight, fullScreen);
}

/// <summary>
/// This method calls an initialization function in RenderFacade with the given data, like resolution of the game window.
/// </summary>
/// <param name="title">Title of game window.</param>
/// <param name="width">Width of game window.</param>
/// <param name="height">Height of game window.</param>
/// <param name="fullscreen">Boolean whether game is fullscreen or not.</param>
void EngineController::initRenderer(const std::string& title, int width, int height, bool fullscreen)
{
	renderFacade->init(title, width, height, fullscreen);
}

void EngineController::staticPassCameraDimensionFunction(void* p, const Transform& transform)
{
	((EngineController*)p)->passCameraDimensionFunction(transform);
}

void EngineController::passCameraDimensionFunction(const Transform& transform)
{
	collision->setCameraDimensions(transform);
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
	sceneManager.setSceneSwitched(false);
	if (keyCode == KeyCodes::KEY_F10)
	{
		quitGame();
	}
	else {
		sceneManager.handleSceneInput(keyCode, keyboardEvent, mousePos);
	}
}
#pragma endregion Input handling

/// <summary>
/// This method adds a texture to the AssetManager so that the texture is a known asset.
/// </summary>
/// <param name="name">Texture name.</param>
/// <param name="path">Texture path.</param>
void EngineController::addTexture(const std::string& name, const std::string& path)
{
	textureAssetManager->addAsset(name, path);
}

void EngineController::createCamera(const int x, const int y)const
{
	renderFacade->createCamera(x, y);
}

/// <summary>
/// This method contains the game loop from which a few functions that need constant updating, are executed.
/// </summary>
void EngineController::startGame()
{
	while (renderFacade->renderer->isRunning)
	{
		renderFacade->setFrameStart();
		if (!isGameOver && !renderFacade->renderer->transitioning)
		{
			input->handleInput(renderFacade->renderer->isPaused);
		}
		if (!renderFacade->renderer->isPaused)
		{
			renderFacade->beforeFrame();
			sceneManager.update();
		}
		checkTransition();
		checkGameOver();
		renderFacade->afterFrame();
		renderFacade->setFrameDelay();
	}
}

void EngineController::registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
{
	std::vector<std::shared_ptr<BehaviourObject>> colliderObjects;

	std::vector<std::shared_ptr<BehaviourObject>> containedObjects;
	for (auto& o : behaviourObjects)
	{
		if (dynamic_cast<GameObject*>(o.get()) != nullptr)
		{
			auto go = dynamic_cast<GameObject*>(o.get());
			auto gor = go->getComponentsRecursive();
			for (auto& bo : gor)
			{
				containedObjects.emplace_back(bo);
			}
		}
	}

	for (auto& co : containedObjects)
	{
		behaviourObjects.emplace_back(co);
	}

	for (const auto& o : behaviourObjects)
	{
		if (dynamic_cast<GraphicsComponent*>(o.get()) != nullptr)
		{
			auto ngc = dynamic_cast<GraphicsComponent*>(o.get());
			ngc->addTextureManager(textureManager);
		}
		else if (dynamic_cast<CollidingComponent*>(o.get()) != nullptr)
		{
			colliderObjects.emplace_back(o);
		}
		else if (dynamic_cast<TextComponent*>(o.get()) != nullptr)
		{
			auto ntc = dynamic_cast<TextComponent*>(o.get());
			ntc->addFontManager(fontManager);
		}
	}
	collision->registerColliders(colliderObjects);
	sceneManager.registerScene(sceneName, behaviourObjects);
}

void EngineController::loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious)
{
	if (renderFacade->renderer->isPaused)
	{
		renderFacade->pauseGame();
	}
	sceneManager.loadScene(sceneName, fromScene, clearPrevious);
	transitionScene();
}

void EngineController::loadPreviousScene()
{
	sceneManager.loadPreviousScene();
	if (!sceneManager.isOverlayScene)
	{
		transitionScene();
	}
}

void EngineController::addOverlayScene(const std::string& sceneName)
{
	sceneManager.addOverlayScene(sceneName);
}

void EngineController::transitionScene()
{
	renderFacade->transition();
}

void EngineController::passPlayerPosition(int x, int y)
{
	std::tuple<int, int> positions = renderFacade->passPlayerPosition(x, y);
}

/// <summary>
/// This method registers all given textures, in the AssetManager.
/// </summary>
/// <param name="textures">Map of multiple textures.</param>
void EngineController::registerTextures(const std::map<std::string, std::string> textures) {
	for (const auto& t : textures)
	{
		textureAssetManager->addAsset(t.first, t.second);
	}
}

/// <summary>
/// This method registers all given fonts, in the AssetManager.
/// </summary>
/// <param name="fonts">Map of multiple fonts.</param>
void EngineController::registerFonts(std::map<std::string, std::string> fonts) {
	for (auto& t : fonts)
	{
		fontAssetManager->addAsset(t.first, t.second);
	}
}

void EngineController::registerAudio(std::map<std::string, std::string> tracks) {
	for (auto& t : tracks)
	{
		audioAssetManager->addAsset(t.first, t.second);
	}
}

void EngineController::pauseScreen()
{
	if (renderFacade->renderer->isPaused && sceneManager.getCurrentScene() == "PauseScreen")
	{
		renderFacade->pauseGame();
		loadPreviousScene();
	}
	else if (!renderFacade->renderer->isPaused)
	{
		renderFacade->pauseGame();
		addOverlayScene("PauseScreen");
	}
}

void EngineController::quitGame() const
{
	renderFacade->quitGame();
}

int EngineController::getFPS() const
{
	return renderFacade->getFPS();
}

void EngineController::slowDownGame() const
{
	renderFacade->slowDownGame();
}

void EngineController::speedUpGame() const
{
	renderFacade->speedUpGame();
}

void EngineController::resetSpeedGame() const
{
	renderFacade->resetSpeedGame();
}

void EngineController::addObjectToScene(std::shared_ptr<BehaviourObject> addObject)
{
	if (dynamic_cast<GraphicsComponent*>(addObject.get()) != nullptr)
	{
		auto ngc = dynamic_cast<GraphicsComponent*>(addObject.get());
		ngc->addTextureManager(textureManager);
		sceneManager.addObjectToScene(addObject);
	}
	else
	{
		sceneManager.addObjectToScene(addObject);
	}
}

void EngineController::passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h)
{
	sceneManager.passInteract(player, x, y, w, h);
}

void EngineController::passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w)
{
	collision->checkCollision(collider, behaviourObject, x, y, direction, w);
}

void EngineController::throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w)
{
	collision->checkProjectileCollision(collider, x, y, direction, w);
}

void EngineController::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	sceneManager.deleteObjectFromScene(deletedObject);
}

void EngineController::deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider)
{
	collision->deleteColliderFromScene(deletedCollider);
}

void EngineController::gameOver()
{
	isGameOver = true;
}

void EngineController::checkGameOver()
{
	if (isGameOver)
	{
		if (timer == 0) {
			isGameOver = false;
			timer = 30;
			loadScene("GameOverScreen", "", true);
		}
		else
		{
			timer--;
		}
	}
}

void EngineController::checkTransition()const
{
	renderFacade->checkTransition();
}

void EngineController::playAudio(const std::string& trackName, bool looped)
{
	audioManager->playAudio(trackName, looped);
}

void EngineController::deleteScene(const std::string& sceneName)
{
	sceneManager.deleteScene(sceneName);
}

void EngineController::replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects)
{

	for (const auto& o : objects)
	{
		if (dynamic_cast<GraphicsComponent*>(o.get()) != nullptr)
		{
			auto ngc = dynamic_cast<GraphicsComponent*>(o.get());
			ngc->addTextureManager(textureManager);
		}
		else if (dynamic_cast<TextComponent*>(o.get()) != nullptr)
		{
			auto ntc = dynamic_cast<TextComponent*>(o.get());
			ntc->addFontManager(fontManager);
		}
	}
	sceneManager.replaceScene(sceneName, objects);
}