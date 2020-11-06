#pragma once

#include "IInputFacade.h"
#include "InputWrapper.h"
#include <memory>
typedef void(*callbackFunction) (void*, KeyCodes, KeyboardEvent);

class InputFacade : public IInputFacade
{
public:
	InputFacade();
	InputFacade(const cbFunction f, void* p);
};