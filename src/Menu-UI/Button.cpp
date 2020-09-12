#include "Menu-UI/Button.h"

Button::Button(std::string text, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : _text(text),
      UIElement(position, rotation, scale, visible, disabled)
{
}

Button::~Button()
{
}

void Button::render()
{
}

void Button::press()
{
}