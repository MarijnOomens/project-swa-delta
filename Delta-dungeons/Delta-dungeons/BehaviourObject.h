#pragma once
#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"

class BehaviourObject {
	virtual void callbackFunction() = 0;
	virtual void connectCallback() = 0;
	
public:
	virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) = 0;
	virtual void update() = 0;
	Transform transform;
	BehaviourObject();
	~BehaviourObject();

};
