#include "InputFacade.h"

InputFacade::InputFacade(const cbFunction f) {
	wrapper = std::make_unique<InputWrapper>(f);
}

void IInputFacade::handleEvents() {

}

void IInputFacade::mapKeyBindings(Keycodes code)
{

}