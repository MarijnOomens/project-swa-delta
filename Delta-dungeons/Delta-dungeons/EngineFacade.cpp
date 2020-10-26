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

void registerBehaviourObjects(std::vector<BehaviourObject> objects) {

}