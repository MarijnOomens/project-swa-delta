#pragma once
#include "BehaviourObject.h";
#include <vector>;
//#include "BehaviourObject.h"
#include "GraphicsComponent.h"

class GameObject : BehaviourObject {
public:
	GameObject();
	~GameObject();

	GraphicsComponent graphicsComponent;
	void ConnectCallback(); //Add callbackfunction
private:
	std::vector<BehaviourObject> components;
	void Update();
	void draw();
	bool checkGraphicsComponent();
};