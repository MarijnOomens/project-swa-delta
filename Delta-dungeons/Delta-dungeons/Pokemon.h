#pragma once

#include "IInteractiveObject.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include <string>
#include <map>
#include "DamageStrategy.h"
#include "SceneModifier.h"
#include "AudioUtilities.h"

typedef void(*cbCollision) (void*, std::shared_ptr<CollidingComponent>, std::shared_ptr<BehaviourObject> behaviourObject, int, int, KeyCodes, int);
typedef bool(*cbCameraRange) (void*, int, int);

class Pokemon : public IInteractiveObject
{
public:
	Pokemon(int x, int y, const std::string &texture, cbCollision collisionCb, cbCameraRange cameraCb, void* p, int attackTime);
	void interact(std::shared_ptr<BehaviourObject> interactor) override {}
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos) override {}
	void catchPokemon();
	void setParent() override;
	void start() override {}
	void update(int time) override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override;
	void walk();
	void playAnimation(int direction);
protected:
	std::string sfxPath;

private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::string type;
	int attackTime;
	cbCollision func;
	cbCameraRange cameraFunc;
	void* pointer;
	int id;
	int catchRate;
	int previoustime = 0;
	const int animationSpeed = 180;
	bool hasMoved = false;
};