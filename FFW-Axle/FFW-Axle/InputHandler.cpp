#include "InputHandler.h"
#include "Exception.h"


InputHandler::InputHandler()
{
	_keyboardHandler = &KeyboardHandler::getKeyboard();
	_mouseHandler = &MouseHandler::getMouse();
	_gamePadHandler = &GamePadHandler::getGamePad();
}


InputHandler::~InputHandler()
{
	_keyboardHandler->destroyKeyboard();
	_mouseHandler->destroyMouse();
	_gamePadHandler->destroyGamePad();
}


InputHandler& InputHandler::getInputHandler()
{
	static InputHandler* handler = NULL;
	if (handler == NULL)
	{
		handler = new InputHandler();
	}
	return *handler;
}

void InputHandler::destroyInputHandler()
{
	InputHandler* handler = &getInputHandler();
	if (handler == NULL)
	{
		return;
	}
	delete handler; // frees the memory of the handler
	handler = NULL;
}


bool InputHandler::getKeyState(int key)
{
	if (checkIfNULL(_keyboardHandler,"Trying to access the key state of a NULL keyboard", EXCEPTION_CATCH))
	{
		printf("Recovering...\nCreating a keyboard handler...\n");
		_keyboardHandler = &KeyboardHandler::getKeyboard();
	}
	return _keyboardHandler->getKeyState(key);
}
bool InputHandler::getButtonState(int button)
{
	if (checkIfNULL(_mouseHandler,"Trying to access the state of the a NULL mouse", EXCEPTION_CATCH))
	{
		printf("Recovering...\nCreating a mouse handler...\n");
		_mouseHandler = &MouseHandler::getMouse();
	}
	return _mouseHandler->getMouseState(button);
}

glm::vec2 InputHandler::getMousePosition()
{
	if (checkIfNULL(_mouseHandler,"Trying to access the state of the a NULL mouse", EXCEPTION_CATCH))
	{
		printf("Recovering...\nCreating a mouse handler...\n");
		_mouseHandler = &MouseHandler::getMouse();
	}
	glm::vec2 pos;
	pos.x = (float)_mouseHandler->getX();
	pos.y = (float)_mouseHandler->getY();
	return pos;
}