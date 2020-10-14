#pragma once
#include "Keycodes.h"
#include "InputWrapper.h"
#include <memory>

class IInputFacade 
{
public:
	InputWrapper* wrapper;
	virtual void handleEvents();
	virtual void mapKeyBindings(Keycodes code);
};