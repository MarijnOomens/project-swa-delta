#pragma once

#include "Keycodes.h"
#include "Keyboardevent.h"
#include "InputWrapper.h"
#include <memory>

class IInputFacade
{
public:
	std::unique_ptr<InputWrapper> inputWrapper;

	virtual void handleInput(bool isPaused) = 0;
	virtual void mapKeyBindings(const KeyCodes& code) = 0;
};