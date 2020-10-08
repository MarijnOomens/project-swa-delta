#pragma once
//#include "BehaviourObject.h"
#include "GraphicsComponent.h"

class GameObject {
public:
	GameObject();
	~GameObject();

	GraphicsComponent graphicsComponent;
	void ConnectCallback(); //Add callbackfunction
	void Update();
	void draw();
	bool checkGraphicsComponent();
};