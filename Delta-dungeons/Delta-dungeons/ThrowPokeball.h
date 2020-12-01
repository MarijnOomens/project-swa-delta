#pragma once
#include <iostream>
#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "StopStrategy.h"

typedef void(*cbSentPokemon) (void*);
class ThrowPokeball : public IEquipment
{
public:
	ThrowPokeball() {}
	ThrowPokeball(const cbSentPokemon f, void* p);


	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
	void setParent() override;
	void update() override;
private:
	cbSentPokemon func;
	void* pointer;

	bool isMoving;
	std::string direction;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<CollidingComponent> cc;

};