#pragma once
#include "Keycodes.h"
#include "InputWrapper.h"

class IInputFacade 
{
public:
	virtual void handleEvents();
	virtual void mapKeyBindings(Keycodes code);
};