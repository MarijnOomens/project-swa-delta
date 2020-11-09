#pragma once

#include "Keycodes.h"
#include "Keyboardevent.h"
#include "InputWrapper.h"
#include <memory>

class IInputFacade
{
public:
	std::unique_ptr<InputWrapper> wrapper;
	virtual void handleInput(bool isPaused);
	virtual void mapKeyBindings(KeyCodes code);
};