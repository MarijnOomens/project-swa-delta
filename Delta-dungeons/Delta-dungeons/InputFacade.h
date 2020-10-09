#pragma once
#include "IInputFacade.h"
#include "InputWrapper.h"
typedef void(*cbFunction) (Keycodes);

class InputFacade: IInputFacade
{
public:
	InputWrapper wrapper;
	InputFacade(cbFunction f);
	void handle();

};