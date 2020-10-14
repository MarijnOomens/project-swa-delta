#include "InputFacade.h"

InputFacade::InputFacade() {};

InputFacade::InputFacade(const cbFunction f) {
	wrapper = new InputWrapper(f);
}

void IInputFacade::handleEvents() 
{
	wrapper->handleEvents();
}

void IInputFacade::mapKeyBindings(Keycodes code)
{

}