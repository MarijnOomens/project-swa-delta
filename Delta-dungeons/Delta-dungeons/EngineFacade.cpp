#include "EngineFacade.h"

//EngineFacade::EngineFacade() {
//	engineController = std::make_unique<EngineController>();
//}

void EngineFacade::init() {
	engineController = std::make_unique<EngineController>();
}

void EngineFacade::addTexture(std::string name, std::string path){
	engineController->addTexture(name, path);
};

void EngineFacade::registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) {
	engineController->registerBehaviourObjects(objects);
}

void EngineFacade::registerTextures(std::map<std::string, std::string> textures) {
	engineController.get()->registerTextures(textures);
}

void EngineFacade::startGame() {
	engineController.get()->startGame();
}