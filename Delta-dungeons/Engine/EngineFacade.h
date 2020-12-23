#pragma once

#include <string>
#include "EngineController.h"
#include "main.h"

class EngineFacade
{
public:
	ENGINE_API EngineFacade() {}
	ENGINE_API ~EngineFacade() {}

	ENGINE_API void init(const std::string& title, int screenWidth, int screenHeight, bool fullScreen);
	ENGINE_API void addTexture(const std::string& name, const std::string& path) const;
	ENGINE_API void registerBehaviourObjects(std::vector<std::shared_ptr<BehaviourObject>> objects) const;
	ENGINE_API void registerTextures(std::map<std::string, std::string> textures) const;
	ENGINE_API void registerFonts(std::map<std::string, std::string> fonts) const;
	ENGINE_API void registerAudio(std::map<std::string, std::string> tracks) const;
	ENGINE_API void startGame() const;
	ENGINE_API void createCamera(int x, int y) const;
	ENGINE_API void passPlayerPosition(int x, int y) const;
	ENGINE_API void registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects) const;
	ENGINE_API void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious) const;
	ENGINE_API void loadPreviousScene() const;
	ENGINE_API void addOverlayScene(const std::string& sceneName) const;
	ENGINE_API void quitGame() const;
	ENGINE_API int getFPS() const;
	ENGINE_API void slowDownGame() const;
	ENGINE_API void speedUpGame() const;
	ENGINE_API void resetSpeedGame() const;
	ENGINE_API void pauseGame() const;
	ENGINE_API void addObjectToScene(std::shared_ptr<BehaviourObject> addObject) const;
	ENGINE_API void passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h) const;
	ENGINE_API void passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w) const;
	ENGINE_API void throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w) const;

	ENGINE_API void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject) const;
	ENGINE_API void deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider) const;
	ENGINE_API void gameOver() const;
	ENGINE_API void playAudio(const std::string& trackName, bool looped) const;
	ENGINE_API void playEffect(const std::string& effectName) const;
	ENGINE_API void deleteScene(const std::string& sceneName) const;
	ENGINE_API void replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects) const;
	ENGINE_API bool checkInRangeCamera(int x, int y) const;
	ENGINE_API void checkAiCollision(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w) const;

private:
	std::unique_ptr<EngineController> engineController;
};