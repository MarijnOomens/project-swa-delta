#include "Input.h"

/// <summary>
/// This class serves as a communication class between InputFacade and EngineController. Input data is received from InputFacade here.
/// </summary>

Input::Input(const cbFunction f, void* p) :func(f), pointer(p)
{
	facade = std::make_unique<InputFacade>(staticCallbackFunction, this);
}

void Input::staticCallbackFunction(void* p, const KeyCodes keyCode, const KeyboardEvent keyboardEvent, Vector2D mousePos)
{
	((Input*)p)->callBackFunction(keyCode, keyboardEvent, mousePos);
}

void Input::handleInput(bool isPaused, bool inConversation) const
{
	facade->handleInput(isPaused, inConversation);
}

void Input::callBackFunction(const KeyCodes keyCode,const KeyboardEvent keyboardEvent, Vector2D mousePos) const
{
	func(pointer, keyCode, keyboardEvent, mousePos);
}

void Input::parseKeyBindings(const std::string& string) const {}