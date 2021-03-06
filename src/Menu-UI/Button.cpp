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

std::string Button::getText()
{
  return _text;
}

void Button::setText(std::string text)
{
  _text = text;
}

UIElement Button::toParentObject() const
{
  return ((UIElement)(*this));
}

bool Button::operator==(const Button &button)
{
  return (this->_text == button._text && this->toParentObject() == button.toParentObject());
}

bool Button::operator!=(const Button &button)
{
  return !((*this) == button);
}