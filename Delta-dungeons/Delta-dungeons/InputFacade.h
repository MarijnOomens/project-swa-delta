#pragma once
#include "IInputFacade.h"
#include "InputWrapper.h"
#include <memory>
typedef void(*cbFunction) (KeyCodes, KeyboardEvent);

class InputFacade : public IInputFacade
{
public:
	InputFacade();
	InputFacade(const cbFunction f);
};