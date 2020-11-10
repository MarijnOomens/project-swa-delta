#pragma once
#include <string>
#include "EngineController.h"

class EngineFacade {
public:
	std::unique_ptr<EngineController> engineController;
	void init();
	void addTexture(std::string name, std::string path);
	void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects);
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void startGame();
	void createCamera(int x, int y);
	void passPlayerPosition(int x, int y);
	void registerScene(std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	void loadScene(std::string sceneName, std::string fromScene, bool clearPrevious);
	void loadPreviousScene();
	void addOverlayScene(const std::string& sceneName);
	void quitGame();

};