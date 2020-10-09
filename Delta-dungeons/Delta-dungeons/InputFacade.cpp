#include "InputFacade.h"
#include <iostream>


InputFacade::InputFacade(cbFunction f) {
	wrapper = InputWrapper(f);
}

void InputFacade::handle() 
{
	wrapper.handleEvents();
}

void IInputFacade::handleEvents() {

}

void IInputFacade::mapKeyBindings(Keycodes code)
{

}