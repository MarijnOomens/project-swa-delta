#include "EngineFacade.h"
/// <summary>
/// Facade between EngineController & GameManager
/// </summary>

//EngineFacade::EngineFacade() {
//	engineController = std::make_unique<EngineController>();
//}

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

void EngineFacade::addTexture(std::string name, std::string path) 
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
	engineController.get()->registerTextures(textures);
}

/// <summary>
/// Calls registerFonts from the GameManager in the EngineController.
/// </summary>
void EngineFacade::registerFonts(std::map<std::string, std::string> fonts) 
{
	engineController.get()->registerFonts(fonts);
}

/// <summary>
///  Calls startGame from the GameManager in the EngineController.
/// </summary>
void EngineFacade::startGame() 
{
	engineController.get()->startGame();
}

void EngineFacade::createCamera(int x, int y) 
{
	engineController.get()->createCamera(x,y);
}

void EngineFacade::passPlayerPosition(int x, int y)
{
	engineController.get()->passPlayerPosition(x, y);
}

void EngineFacade::registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects)
{
	engineController.get()->registerScene(sceneName, behaviourObjects);
}

void EngineFacade::loadScene(std::string sceneName, std::string fromScene, bool clearPrevious)
{
	engineController.get()->loadScene(sceneName, fromScene, clearPrevious);
}

void EngineFacade::loadPreviousScene()
{
	engineController.get()->loadPreviousScene();
}

void EngineFacade::addOverlayScene(const std::string& sceneName)
{
	engineController.get()->addOverlayScene(sceneName);
}

void EngineFacade::quitGame() {
	engineController->quitGame();
}
