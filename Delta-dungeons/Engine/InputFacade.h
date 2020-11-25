#pragma once

#include "IInputFacade.h"
#include "InputWrapper.h"
#include <memory>

typedef void(*callbackFunction) (void*, KeyCodes, KeyboardEvent, Vector2D);

class InputFacade : public IInputFacade
{
public:
	InputFacade() {}
	InputFacade(const cbFunction f, void* p);

	void handleInput(const bool isPaused) const override;
	void mapKeyBindings(const KeyCodes& code) override;
};