#include "InputFacade.h"
#include <iostream>

void callbackFunction(Keycodes code)
{
	std::cout << code + "has been passed to the facade" << std::endl;
	/*my_func(code);*/
}

InputFacade::InputFacade(cbFunction f) {
	my_func = f;
	wrapper = InputWrapper(callbackFunction);
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