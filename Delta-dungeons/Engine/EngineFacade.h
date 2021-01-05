#pragma once

#include <string>
#include "EngineController.h"
#include "main.h"

/// <summary>
/// Facade between EngineController & GameManager
/// </summary>
/// This class servers as the main interface between the engine and game implementation. All global functions that may be used on the engine for registering scenes,
/// modifying scenes, playing audio etc. can be called here. It also serves as the starting point for initialising the application.
class EngineFacade
{
public:
	ENGINE_API EngineFacade() {}
	ENGINE_API ~EngineFacade() {}

	/// <summary>
	///  Init creates a unique EngineController, and calls it's constructor.
	/// </summary>
	/// This method initialises the game window and SDL functions. It has to be called first in order for any SDL functionality to work.
	ENGINE_API void init(const std::string& title, int screenWidth, int screenHeight, bool fullScreen);
	/// <summary>
	/// Adds a texture to the game's resources, whereafter it can be called by it's name instead of it's path.
	/// </summary>
	ENGINE_API void addTexture(const std::string& name, const std::string& path) const;
	/// <summary>
	/// Add multiple textures with name to the game's resouces
	/// </summary>
	ENGINE_API void registerTextures(std::map<std::string, std::string> textures) const;
	/// <summary>
	/// Add multiple fonts with name to the game's resouces
	/// </summary>
	ENGINE_API void registerFonts(std::map<std::string, std::string> fonts) const;
	/// <summary>
	/// Add multiple audio tracks with name to the game's resouces
	/// </summary>
	ENGINE_API void registerAudio(std::map<std::string, std::string> tracks) const;
	/// <summary>
	/// Starts the game loop, call this method after every object, scene and resource is registered
	/// </summary>
	ENGINE_API void startGame() const;
	/// <summary>
	/// This method creates the game's camera, to be called when creating a level where a camera is required
	/// </summary>
	ENGINE_API void createCamera(int x, int y) const;
	/// <summary>
	/// This method can be called whenever the player moves, or when the camera has to be moved. Moves the camera to focus on given position
	/// </summary>
	ENGINE_API void passPlayerPosition(int x, int y) const;
	/// <summary>
	/// Registers a scene by name that includes BehaviourObjects
	/// </summary>
	ENGINE_API void registerScene(const std::string& sceneName, std::vector<std::shared_ptr<BehaviourObject>> behaviourObjects) const;
	/// <summary>
	/// Loads a previously registered scene by name
	/// </summary>
	ENGINE_API void loadScene(const std::string& sceneName, const std::string& fromScene, bool clearPrevious) const;
	/// <summary>
	/// Loads the previous scene that was loaded
	/// </summary>
	ENGINE_API void loadPreviousScene() const;
	/// <summary>
	/// Loads a scene by name as an overlay scene, the previously loaded scene keeps existing in the background
	/// </summary>
	ENGINE_API void addOverlayScene(const std::string& sceneName) const;
	ENGINE_API void quitGame() const;
	/// <summary>
	/// Gets the frames per second the game is currently running at
	/// </summary>
	ENGINE_API int getFPS() const;
	/// <summary>
	/// Slows down the game by 10%
	/// </summary>
	ENGINE_API void slowDownGame() const;
	/// <summary>
	/// Speeds the game up by 10%
	/// </summary>
	ENGINE_API void speedUpGame() const;
	/// <summary>
	/// Reset the gamespeed
	/// </summary>
	ENGINE_API void resetSpeedGame() const;
	/// <summary>
	/// Pauses the game logic, input is still registered
	/// </summary>
	ENGINE_API void pauseGame() const;
	/// <summary>
	/// Pauses the game input, the logic is not paused
	/// </summary>
	ENGINE_API void pauseInput() const;
	/// <summary>
	/// Adds a BehaviourObject to a scene that is already registered
	/// </summary>
	ENGINE_API void addObjectToScene(std::shared_ptr<BehaviourObject> addObject) const;
	/// <summary>
	/// This function passes an interaction check for interaction between 2 different BehaviourObjects
	/// </summary>
	ENGINE_API void passInteract(std::shared_ptr<BehaviourObject> player, int x, int y, int w, int h) const;
	/// <summary>
	/// Statically checks collision for a BehaviourObject
	/// </summary>
	ENGINE_API void passCollisionCheck(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w) const;
	/// <summary>
	/// Dynamically checks collision for a BehaviourObject
	/// </summary>
	ENGINE_API void throwCollisionCheck(std::shared_ptr<BehaviourObject> collider, int x, int y, KeyCodes direction, int w) const;
	/// <summary>
	/// Deletes a BehaviourObject from a scene that is already registered
	/// </summary>
	ENGINE_API void deleteObjectFromScene(std::shared_ptr<BehaviourObject> deletedObject) const;
	/// <summary>
	/// Deletes a collider from a scene that is already registered
	/// </summary>
	ENGINE_API void deleteColliderFromScene(std::shared_ptr<CollidingComponent> deletedCollider) const;
	/// <summary>
	/// Triggers a fail condition for when the player fails the game
	/// </summary>
	ENGINE_API void gameOver() const;
	/// <summary>
	/// Plays a regular audio track
	/// </summary>
	ENGINE_API void playAudio(const std::string& trackName, bool looped) const;
	/// <summary>
	/// Plays a sound effect, which must have been registeres as a .wav file
	/// </summary>
	ENGINE_API void playEffect(const std::string& effectName) const;
	/// <summary>
	/// Deletes a scene and all it's contents from the SceneManager
	/// </summary>
	ENGINE_API void deleteScene(const std::string& sceneName) const;
	/// <summary>
	/// Replaces an existing scene by a new one
	/// </summary>
	ENGINE_API void replaceScene(const std::string sceneName, std::vector<std::shared_ptr<BehaviourObject>> objects) const;
	/// <summary>
	/// Return true when the passes coordinates are within the game camera's range, false if not
	/// </summary>
	ENGINE_API bool checkInRangeCamera(int x, int y) const;
	/// <summary>
	/// Checks collision for a non-player object
	/// </summary>
	ENGINE_API void checkAiCollision(std::shared_ptr<CollidingComponent> collider, std::shared_ptr<BehaviourObject> behaviourObject, int x, int y, KeyCodes direction, int w) const;

private:
	std::unique_ptr<EngineController> engineController;
};