#pragma once
#include "IInputFacade.h"
#include "InputWrapper.h"
#include <memory>
typedef void(*cbFunction) (Keycodes);

class InputFacade: IInputFacade
{
public:
	std::unique_ptr<InputWrapper> wrapper;
	InputFacade(const cbFunction f);
};