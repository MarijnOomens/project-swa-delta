#pragma once
#include "BehaviourObject.h";
#include <vector>;
#include "GraphicsComponent.h"

class GameObject : BehaviourObject {
public:
	GameObject();
	~GameObject();

	GraphicsComponent graphicsComponent;
	void ConnectCallback(); //Add callbackfunction
	void Update();
	void draw();
private:
	std::vector<BehaviourObject> components;
	bool checkGraphicsComponent();
};