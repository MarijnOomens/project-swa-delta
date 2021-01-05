#pragma once
#include "main.h"
#include "TextureManager.h"
#include "BehaviourObject.h"
#include "AnimTypes.h"
#include "AnimFlip.h"
#include "AnimCategory.h"
#include <iostream>

/// <summary>
/// A GraphicsComponent holds the graphical aspect of a gameObject, like animation and textures.
/// </summary>
class GraphicsComponent : public BehaviourObject {
public:
	Vector2D imageCoordinates;
	Vector2D imageDimensions = { 32, 32 };
	bool isScreen;

	ENGINE_API GraphicsComponent() {};

	/// <summary>
	/// If the graphicsComponent is animated, this method will start to play the animation every animation tick.
	/// </summary>
	/// <param name="row">The row of which animation frame to take.</param>
	/// <param name="frames">The amount of frames in an animation.</param>
	/// <param name="speed">The speed of the animation.</param>
	/// <param name="flip">If the animation is flipped or not.</param>
	ENGINE_API void playAnimation(int row, int frames, int speed, bool flip);
	/// <summary>
	/// Sets the texture to the given name
	/// </summary>
	ENGINE_API void setTexture(const std::string& name);
	/// <summary>
	/// Gets called every game tick when the scene containing this GraphicsComponent is loaded in, redraws the texture for the next frame
	/// </summary>
	ENGINE_API void update(int time) override;
	/// <summary>
	/// Inject the TextureManager
	/// </summary>
	ENGINE_API void addTextureManager(std::shared_ptr<TextureManager> tm);
	/// <summary>
	/// See BehaviourObject
	/// </summary>
	ENGINE_API void handleInput(const KeyCodes &keyCode, const KeyboardEvent &keyboardEvent, Vector2D &mousePos);
	/// <summary>
	/// See BehaviourObject
	/// </summary>
	ENGINE_API void interact(std::shared_ptr<BehaviourObject> interactor) override;
	/// <summary>
	/// See BehaviourObject
	/// </summary>
	ENGINE_API void start() override;
	/// <summary>
	/// See BehaviourObject
	/// </summary>
	ENGINE_API void setParent() override;
	/// <summary>
	/// Return the TextureManger this GraphicsComponent uses
	/// </summary>
	ENGINE_API std::shared_ptr<TextureManager>getTextureManager() const;
	/// <summary>
	/// The name of the texture this GraphicsComponent uses
	/// </summary>
	std::string textureName;

private:
	bool animated = false;
	int animFrames;
	int animSpeed;
	int animRow;
	bool flipped = false;

	std::map<std::string, AnimTypes> animTypes;
	std::shared_ptr<TextureManager> textureManager;
};