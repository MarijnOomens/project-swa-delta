#pragma once

#include <string>
#include "EngineController.h"
#include "main.h"

class EngineFacade 
{
public:
	ENGINE_API EngineFacade() {}
	ENGINE_API ~EngineFacade() {}

	ENGINE_API void init();
	ENGINE_API void addTexture(const std::string& name, const std::string& path);
	ENGINE_API void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects);
	ENGINE_API void registerTextures(std::map<std::string, std::string> textures);
	ENGINE_API void registerFonts(std::map<std::string, std::string> fonts);
	ENGINE_API void startGame();
	ENGINE_API void createCamera(int x, int y);
	ENGINE_API void passPlayerPosition(int x, int y);
	ENGINE_API void registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	ENGINE_API void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious);
	ENGINE_API void loadPreviousScene();
	ENGINE_API void addOverlayScene(const std::string& sceneName);
	ENGINE_API void quitGame();
	ENGINE_API int getFPS();
	ENGINE_API void slowDownGame();
	ENGINE_API void speedUpGame();
	ENGINE_API void resetSpeedGame();
	ENGINE_API void pauseGame();
	ENGINE_API void passInteract(int x, int y);


private:
	std::unique_ptr<EngineController> engineController;
};