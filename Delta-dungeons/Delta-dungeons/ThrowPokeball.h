#pragma once
#include <iostream>
#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "StopStrategy.h"
#include "Pokemon.h"
#include "GameState.h"

typedef void(*cbSentPokemon) (void*);
typedef void(*cbThrowCollision) (void*, std::shared_ptr<BehaviourObject>, int, int, KeyCodes, int);

class ThrowPokeball : public IEquipment
{
public:
	ThrowPokeball(const cbThrowCollision tF, const cbSentPokemon f, void* p, void* g);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override {}
	void start() override {}
	void setParent() override;
	void registerCollision(int x, int y, bool isDamaged, bool isTransitioned, bool isWinTrigger) override {}
	void handleInput(const KeyCodes& keyCode, const KeyboardEvent& keyboardEvent, Vector2D& mousePos)override {}
	void update(int time) override;
	void moveUp(int x, int y);
	void moveDown(int x, int y);
	void moveLeft(int x, int y);
	void moveRight(int x, int y);
	void updateTransform(int x, int y);
	void reset();

	bool isMoving = false;
private:
	cbSentPokemon func;
	cbThrowCollision tFunc;
	void* playerPointer;
	void* gameMangerPointer;

	std::string direction;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;	
	std::shared_ptr<CollisionStrategy> stp;
	
};