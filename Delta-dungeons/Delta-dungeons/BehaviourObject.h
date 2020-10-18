#pragma once
#include "Transform.h";
#include "Keycodes.h"
#include "KeyboardEvent.h"

class BehaviourObject {
	virtual void Update() = 0;
	virtual void callbackFunction() = 0;
	virtual void connectCallback() = 0;
	
public:
	Transform transform;
	BehaviourObject();
	~BehaviourObject();

	virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) = 0;
};
