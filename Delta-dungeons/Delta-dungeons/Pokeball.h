#pragma once

#include <iostream>
#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"
#include "Player.h"

//typedef void(*cbSentPokemon) (void*);
//typedef void(*cbAddPokeball) (void*);
class Pokeball : public IEquipment
{
public:
	Pokeball() {}
	//Pokeball(const cbSentPokemon f, void* p);
	Pokeball(int x, int y, std::string texture);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
	void setParent() override;

private:
	//cbSentPokemon func;
	//cbAddPokeball addFunc;
	void* pointer;
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};