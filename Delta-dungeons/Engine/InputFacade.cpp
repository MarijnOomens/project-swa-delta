#include "InputFacade.h"

/// <summary>
/// Constructor to give functions for callbacks
/// </summary>
/// <param name="f">Function</param>
/// <param name="p"></param>
InputFacade::InputFacade(const cbFunction f, void* p)
{
	inputWrapper = std::make_unique<InputWrapper>(f, p);
}

/// <summary>
/// This function takes the input and gives it to the code behind the facade.
/// </summary>
void InputFacade::handleInput(bool isPaused)
{
	inputWrapper->handleInput(isPaused);
}

void InputFacade::mapKeyBindings(const KeyCodes& keyCode) {}