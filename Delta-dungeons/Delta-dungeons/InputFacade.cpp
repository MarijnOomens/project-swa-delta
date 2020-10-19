#include "InputFacade.h"

InputFacade::InputFacade() {};

InputFacade::InputFacade(const cbFunction f, void *p) {
	wrapper = std::make_unique<InputWrapper>(f,p);
}

void IInputFacade::handleKeyPressed() 
{
	wrapper->handleKeyPressed();
}

void IInputFacade::handleKeyReleased() 
{
	wrapper->handleKeyReleased();
}

void IInputFacade::mapKeyBindings(KeyCodes keyCode)
{

}