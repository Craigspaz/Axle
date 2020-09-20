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

bool Button::operator==(const Button *button)
{
  return (this->_text == button->_text && ((UIElement *)this) == ((UIElement *)button));
}

bool Button::operator!=(const Button *button)
{
  return !(this == button);
}