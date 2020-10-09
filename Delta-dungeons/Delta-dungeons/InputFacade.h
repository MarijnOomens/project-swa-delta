#pragma once
#include "IInputFacade.h"
#include "InputWrapper.h"
typedef void(*cbFunction) (Keycodes);

class InputFacade: IInputFacade
{
public:
	cbFunction my_func;
	InputWrapper wrapper;
	InputFacade(cbFunction f);
	void handle();

};