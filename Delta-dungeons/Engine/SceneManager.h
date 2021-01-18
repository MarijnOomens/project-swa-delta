#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>
#include "BehaviourObject.h"
#include "CollidingComponent.h"
#include "GameObject.h"
#include "GraphicsComponent.h"
#include "TextComponent.h"

typedef int(*cbTime) (void*);
typedef void(*cbTexture) (void*, const std::string&);

class SceneManager {
public:
	bool isOverlayScene = false;

	SceneManager(void* p, cbTime timeCb, cbTexture textureCb): timeFunc(timeCb), textureFunc(textureCb), pointer(p) {}
	~SceneManager() {}

	void update(int time, bool paused);
	void loadScene(const std::string& sceneName,const std::string& fromScene,const bool clearPrevious);
	void registerScene(const std::string& sceneName, const std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects);
	void loadPreviousScene();
	void addOverlayScene(const std::string& sceneName);
	int getActiveScenesSize();
	void setSceneSwitched(bool isSwitched);
	void handleSceneInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos);
	void addObjectToScene(std::shared_ptr<BehaviourObject> addObject);
	void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject);
	void passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h);
	std::string getCurrentScene();
	void deleteTexture(const std::string& sceneName);
	void deleteScene(const std::string& sceneName);
	void replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects);
	std::shared_ptr<BehaviourObject> getBehaviourObject(CollidingComponent* collidingComponent);

private:
	std::map<std::string, std::vector<std::shared_ptr<BehaviourObject>>> scenes;
	std::vector<std::string> activeScenes;
	std::vector<std::string> previousScenes;
	std::string currentScene;
	bool isSceneSwitched = false;
	cbTexture textureFunc;
	cbTime timeFunc;
	void* pointer;
};