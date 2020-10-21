#include "EngineFacade.h"

EngineFacade::EngineFacade() {
	engineController = std::make_unique<EngineController>();
}

void EngineFacade::addTexture(std::string name, std::string path){
	engineController->addTexture(name, path);
};