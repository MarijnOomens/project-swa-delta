#pragma once

#include <iostream>
#include "IEquipment.h"
#include "GraphicsComponent.h"
#include "CollidingComponent.h"
#include "StopStrategy.h"

class Pokeball : public IEquipment
{
public:
	Pokeball() {}
	Pokeball(int x, int y, std::string texture);

	void interact(std::shared_ptr<BehaviourObject> interactor) override;
	void use() override;
private:
	std::shared_ptr<CollisionStrategy> stp;
	std::shared_ptr<GraphicsComponent> gc;
	std::shared_ptr<CollidingComponent> cc;
};