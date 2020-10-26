#include "InputFacade.h"

InputFacade::InputFacade() {}

InputFacade::InputFacade(const cbFunction f, void* p)
{
	wrapper = std::make_unique<InputWrapper>(f, p);
}

void IInputFacade::handleInput()
{
	wrapper->handleInput();
}

void IInputFacade::mapKeyBindings(KeyCodes keyCode) {}