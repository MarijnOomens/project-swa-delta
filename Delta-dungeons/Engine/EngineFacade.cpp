#include "EngineFacade.h"

/// <summary>
/// Facade between EngineController & GameManager
/// </summary>

/// <summary>
///  Init creates a unique EngineController object.
/// </summary>
void EngineFacade::init(const std::string& title, int screenWidth, int screenHeight, bool fullScreen)
{
	engineController = std::make_unique<EngineController>(title, screenWidth, screenHeight, fullScreen);
}

/// <summary>
/// Init creates a unique EngineController object.
/// </summary>

void EngineFacade::addTexture(const std::string& name,const std::string& path) const
{
	engineController->addTexture(name, path);
}

/// <summary>
/// Calls registerBehaviourObjects from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) const
{
	//engineController->registerBehaviourObjects(objects);
}

/// <summary>
/// Calls registerTextures from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerTextures(std::map<std::string, std::string> textures) const
{
	engineController->registerTextures(textures);
}

/// <summary>
/// Calls registerFonts from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerFonts(std::map<std::string, std::string> fonts) const
{
	engineController->registerFonts(fonts);
}

void EngineFacade::registerAudio(std::map<std::string, std::string> tracks) const
{
	engineController->registerAudio(tracks);
}

/// <summary>
///  Calls startGame from the GameManager in the EngineController.
/// </summary>
void EngineFacade::startGame() const
{
	engineController->startGame();
}

void EngineFacade::createCamera(int x, int y) const
{
	engineController->createCamera(x,y);
}

void EngineFacade::passPlayerPosition(int x, int y) const
{
	engineController->passPlayerPosition(x, y);
}

void EngineFacade::registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects) const
{
	engineController->registerScene(sceneName, behaviourObjects);
}

void EngineFacade::loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious) const
{
	engineController->loadScene(sceneName, fromScene, clearPrevious);
}

void EngineFacade::loadPreviousScene() const
{
	engineController->loadPreviousScene();
}

void EngineFacade::addOverlayScene(const std::string& sceneName) const
{
	engineController->addOverlayScene(sceneName);
}

void EngineFacade::quitGame() const
{
	engineController->quitGame();
}

int EngineFacade::getFPS() const
{
	return engineController->getFPS();
}

void EngineFacade::slowDownGame() const
{
	engineController->slowDownGame();
}

void EngineFacade::speedUpGame() const
{
	engineController->speedUpGame();
}

void EngineFacade::resetSpeedGame() const
{
	engineController->resetSpeedGame();
}

void EngineFacade::pauseGame() const
{
	engineController->pauseScreen();
}

void EngineFacade::addObjectToScene(std::shared_ptr<BehaviourObject> addObject) const
{
	engineController->addObjectToScene(addObject);
}

void EngineFacade::passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h) const
{
	engineController->passInteract(player, x, y, w, h);
}

void EngineFacade::passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w) const
{
	engineController->passCollisionCheck(collider, behaviourObject,x, y, direction, w);
}

void EngineFacade::throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w) const
{
	engineController->throwCollisionCheck(collider, x, y, direction, w);
}

void EngineFacade::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject) const
{
	engineController->deleteObjectFromScene(deletedObject);
}

void EngineFacade::deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider) const
{
	engineController->deleteColliderFromScene(deletedCollider);
}

void EngineFacade::gameOver() const
{
	engineController->gameOver();
}

void EngineFacade::playAudio(const std::string& trackName, bool looped) const
{
	engineController->playAudio(trackName, looped);
}

void EngineFacade::playEffect(const std::string& effectName) const
{
	engineController->playEffect(effectName);
}

void EngineFacade::deleteScene(const std::string& sceneName) const
{
	engineController->deleteScene(sceneName);
}

void EngineFacade::replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects) const
{
	engineController->replaceScene(sceneName, objects);
}