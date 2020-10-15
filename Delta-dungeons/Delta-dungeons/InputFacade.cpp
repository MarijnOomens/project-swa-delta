#include "InputFacade.h"

InputFacade::InputFacade() {};

InputFacade::InputFacade(const cbFunction f) {
	wrapper = std::make_unique<InputWrapper>(f);
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