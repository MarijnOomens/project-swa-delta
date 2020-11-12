#pragma once

#include <string>
#include "EngineController.h"

class EngineFacade 
{
public:
	EngineFacade() {}
	~EngineFacade() {}

	void init();
	void addTexture(const std::string& name, const std::string& path);
	void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects);
	void registerTextures(std::map<std::string, std::string> textures);
	void registerFonts(std::map<std::string, std::string> fonts);
	void startGame();
	void createCamera(int x, int y);
	void passPlayerPosition(int x, int y);
	void registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious);
	void loadPreviousScene();
	void addOverlayScene(const std::string& sceneName);
	void quitGame();
	int getFPS();
	void slowDownGame();
	void speedUpGame();
	void resetSpeedGame();

private:
	std::unique_ptr<EngineController> engineController;
};