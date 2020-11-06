#include "InputFacade.h"
/// <summary>
/// Inputfacade takes all the input from the engine and gives it to the class who will handle the input.
/// </summary>
InputFacade::InputFacade() {}

/// <summary>
/// Constructor to give functions for callbacks
/// </summary>
/// <param name="f">Function</param>
/// <param name="p"></param>
InputFacade::InputFacade(const cbFunction f, void* p)
{
	wrapper = std::make_unique<InputWrapper>(f, p);
}

/// <summary>
/// This function takes the input and gives it to the code behind the facade.
/// </summary>
void IInputFacade::handleInput()
{
	wrapper->handleInput();
}

void IInputFacade::mapKeyBindings(KeyCodes keyCode) {}