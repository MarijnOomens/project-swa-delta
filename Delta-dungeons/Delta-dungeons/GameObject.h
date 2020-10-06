#pragma once
#include "BehaviourObject.h"
#include "GraphicsComponent.h"

class GameObject: BehaviourObject {
public:
	GameObject();
	~GameObject();

	GraphicsComponent graphicsComponent;
	void ConnectCallback(); //Add callbackfunction
	void Update();
};