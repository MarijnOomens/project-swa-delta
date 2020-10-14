#pragma once
#include "BehaviourObject.h";
#include <vector>;
#include "GraphicsComponent.h"

class GameObject : public BehaviourObject {
public:
	GameObject();
	~GameObject();

	virtual void ConnectCallback(); //Add callbackfunction
	virtual void Update();
	virtual void draw();
	std::vector<std::unique_ptr<BehaviourObject>> components;
};