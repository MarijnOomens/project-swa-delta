#pragma once
#include "BehaviourObject.h";
#include <vector>;

class GameObject : BehaviourObject {
public:
	GameObject();
	void ConnectCallback(); //Add callbackfunction
private:
	std::vector<BehaviourObject> components;
};