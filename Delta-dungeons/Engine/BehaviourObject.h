#pragma once
#ifdef WIN64
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else 
#define ENGINE_API __declspec(dllimport) 
#endif
#else
#define ENGINE_API
#endif

#include "Transform.h"
#include "Keycodes.h"
#include "KeyboardEvent.h"

class BehaviourObject {
	ENGINE_API virtual void callbackFunction() = 0;
	ENGINE_API virtual void connectCallback() = 0;
	
public:
	ENGINE_API virtual void handleInput(const KeyCodes keyCode, const KeyboardEvent keyboardEvent) = 0;
	ENGINE_API virtual void update() = 0;
	ENGINE_API Transform transform;
	ENGINE_API BehaviourObject();
	ENGINE_API ~BehaviourObject();

};
