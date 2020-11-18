#include "EngineFacade.h"

/// <summary>
/// Facade between EngineController & GameManager
/// </summary>

/// <summary>
///  Init creates a unique EngineController object.
/// </summary>
void EngineFacade::init() 
{
	engineController = std::make_unique<EngineController>();
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

void EngineFacade::passInteract(int x, int y)
{
	engineController->passInteract(x, y);
}

void EngineFacade::deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject)
{
	engineController->deleteObjectFromScene(deletedObject);
}

void EngineFacade::deleteColliderFromScene(std::shared_ptr<ColliderComponent> deletedCollider)
{
	engineController->deleteColliderFromScene(deletedCollider);
}