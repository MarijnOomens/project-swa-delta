#include "InputFacade.h"
#include <iostream>


InputFacade::InputFacade(const cbFunction f) {
	wrapper = std::make_unique<InputWrapper>(f);
}

void InputFacade::handle() 
{
	wrapper->handleEvents();
}

void IInputFacade::handleEvents() {

}

void IInputFacade::mapKeyBindings(Keycodes code)
{

}