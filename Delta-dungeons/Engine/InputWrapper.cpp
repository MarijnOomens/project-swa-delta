#include "InputWrapper.h"
#include <iostream>
/// <summary>
/// Inputwrapper is a class which holds what the inputs are supposed to do.
/// </summary>
InputWrapper::InputWrapper() {}

InputWrapper::InputWrapper(const cbFunction f, void* p) :func(f), pointer(p) {}

InputWrapper::~InputWrapper() {}


/// <summary>
/// The handleInput calls the input based on which keyevent is called.
/// </summary>
void InputWrapper::handleInput(bool isPaused)
{
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			handleKeyPressed(isPaused);
			break;
		case SDL_QUIT:
			func(pointer, KeyCodes::KEY_ESC, KeyboardEvent::KEY_PRESSED, {0, 0});
			break;
		case SDL_KEYUP:
			handleKeyReleased();
			break;
		case SDL_MOUSEBUTTONDOWN:
			handleMouseClicked();
			break;
		}
	}
}

/// <summary>
/// The handleInput calls the input based on which key is pressed
/// </summary>
void InputWrapper::handleKeyPressed(bool isPaused)
{
	Vector2D mousePosition;
	if (!isPaused) {
		switch (event.key.keysym.sym)
		{
		case SDLK_UP:
			func(pointer, KeyCodes::KEY_UP, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_DOWN:
			func(pointer, KeyCodes::KEY_DOWN, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_LEFT:
			func(pointer, KeyCodes::KEY_LEFT, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_RIGHT:
			func(pointer, KeyCodes::KEY_RIGHT, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_w:
			func(pointer, KeyCodes::KEY_W, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_a:
			func(pointer, KeyCodes::KEY_A, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_s:
			func(pointer, KeyCodes::KEY_S, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_d:
			func(pointer, KeyCodes::KEY_D, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_q:
			func(pointer, KeyCodes::KEY_Q, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_e:
			func(pointer, KeyCodes::KEY_E, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_g:
			func(pointer, KeyCodes::KEY_G, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_p:
			func(pointer, KeyCodes::KEY_P, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_h:
			func(pointer, KeyCodes::KEY_H, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_COMMA:
			func(pointer, KeyCodes::KEY_COMMA, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_SLASH:
			func(pointer, KeyCodes::KEY_SLASH, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_PERIOD:
			func(pointer, KeyCodes::KEY_POINT, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_ESCAPE:
			func(pointer, KeyCodes::KEY_ESC, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_TAB:
			func(pointer, KeyCodes::KEY_TAB, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		case SDLK_BACKSPACE:
			func(pointer, KeyCodes::KEY_BACKSPACE, KeyboardEvent::KEY_PRESSED, mousePosition);
			break;
		default:
			break;
		}
	}
	else if (event.key.keysym.sym == SDLK_p) 
	{
		func(pointer, KeyCodes::KEY_P, KeyboardEvent::KEY_PRESSED, mousePosition);
	}
	else if (event.key.keysym.sym == SDLK_ESCAPE)
	{
		func(pointer, KeyCodes::KEY_ESC, KeyboardEvent::KEY_PRESSED, mousePosition);
	}
}


/// <summary>
/// The handleInput calls the input based on which key is released
/// </summary>
void InputWrapper::handleKeyReleased()
{
	Vector2D mousePosition;
	switch (event.key.keysym.sym)
	{
	case SDLK_UP:
		func(pointer, KeyCodes::KEY_UP, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_DOWN:
		func(pointer, KeyCodes::KEY_DOWN, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_LEFT:
		func(pointer, KeyCodes::KEY_LEFT, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_RIGHT:
		func(pointer, KeyCodes::KEY_RIGHT, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_w:
		func(pointer, KeyCodes::KEY_W, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_a:
		func(pointer, KeyCodes::KEY_A, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_s:
		func(pointer, KeyCodes::KEY_S, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_d:
		func(pointer, KeyCodes::KEY_D, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_q:
		func(pointer, KeyCodes::KEY_Q, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_e:
		func(pointer, KeyCodes::KEY_E, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	case SDLK_BACKSPACE:
		func(pointer, KeyCodes::KEY_BACKSPACE, KeyboardEvent::KEY_RELEASED, mousePosition);
		break;
	default:
		break;
	}
}

void InputWrapper::handleMouseClicked() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	Vector2D mousePosition { x, y };
	func(pointer, KeyCodes::MOUSE, KeyboardEvent::MOUSE_CLICKED, mousePosition);
}

void InputWrapper::mapKeyBindings(const KeyCodes code) {}