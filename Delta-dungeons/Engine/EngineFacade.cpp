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

void EngineFacade::addTexture(const std::string& name,const std::string& path) 
{
	engineController->addTexture(name, path);
}

/// <summary>
/// Calls registerBehaviourObjects from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) 
{
	//engineController->registerBehaviourObjects(objects);
}

/// <summary>
/// Calls registerTextures from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerTextures(std::map<std::string, std::string> textures) 
{
	engineController->registerTextures(textures);
}

/// <summary>
/// Calls registerFonts from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerFonts(std::map<std::string, std::string> fonts) 
{
	engineController->registerFonts(fonts);
}

void EngineFacade::registerAudio(std::map<std::string, std::string> tracks)
{
	engineController->registerAudio(tracks);
}

/// <summary>
///  Calls startGame from the GameManager in the EngineController.
/// </summary>
void EngineFacade::startGame() 
{
	engineController->startGame();
}

void EngineFacade::createCamera(int x, int y) 
{
	engineController->createCamera(x,y);
}

void EngineFacade::passPlayerPosition(int x, int y)
{
	engineController->passPlayerPosition(x, y);
}

void EngineFacade::registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
{
	engineController->registerScene(sceneName, behaviourObjects);
}

void EngineFacade::loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious)
{
	engineController->loadScene(sceneName, fromScene, clearPrevious);
}

void EngineFacade::loadPreviousScene()
{
	engineController->loadPreviousScene();
}

void EngineFacade::addOverlayScene(const std::string& sceneName)
{
	engineController->addOverlayScene(sceneName);
}

void EngineFacade::quitGame() {
	engineController->quitGame();
}

int EngineFacade::getFPS() 
{
	return engineController->getFPS();
}

void EngineFacade::slowDownGame()
{
	engineController->slowDownGame();
}

void EngineFacade::speedUpGame()
{
	engineController->speedUpGame();
}

void EngineFacade::resetSpeedGame()
{
	engineController->resetSpeedGame();
}

void EngineFacade::pauseGame()
{
	engineController->pauseScreen();
}

void EngineFacade::addObjectToScene(std::shared_ptr<BehaviourObject> addObject)
{
	engineController->addObjectToScene(addObject);
}

void EngineFacade::passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h)
{
	engineController->passInteract(player, x, y, w, h);
}

void EngineFacade::passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w) {
	engineController->passCollisionCheck(collider, behaviourObject,x, y, direction, w);
}

void EngineFacade::throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w) {
	engineController->throwCollisionCheck(collider, x, y, direction, w);
}

void EngineFacade::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	engineController->deleteObjectFromScene(deletedObject);
}

void EngineFacade::deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider)
{
	engineController->deleteColliderFromScene(deletedCollider);
}

void EngineFacade::gameOver()
{
	engineController->gameOver();
}

void EngineFacade::playAudio(const std::string& trackName, bool looped)
{
	engineController->playAudio(trackName, looped);
}

void EngineFacade::deleteScene(const std::string& sceneName)
{
	engineController->deleteScene(sceneName);
}

void EngineFacade::replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects)
{
	engineController->replaceScene(sceneName, objects);
}