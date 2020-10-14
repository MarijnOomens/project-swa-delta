#pragma once
#include "Keycodes.h"
#include "InputWrapper.h"
#include <memory>

class IInputFacade 
{
public:
	std::unique_ptr<InputWrapper> wrapper;
	virtual void handleEvents();
	virtual void mapKeyBindings(Keycodes code);
};