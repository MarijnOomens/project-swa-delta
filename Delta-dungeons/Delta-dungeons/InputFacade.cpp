#include "InputFacade.h"

InputFacade::InputFacade() {};

InputFacade::InputFacade(const cbFunction f) {
	wrapper = std::make_unique<InputWrapper>(f);
}

void IInputFacade::handleEvents() 
{
	wrapper->handleEvents();
}

void IInputFacade::mapKeyBindings(Keycodes code)
{

}