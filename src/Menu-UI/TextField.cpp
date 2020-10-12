#include "Menu-UI/TextField.h"

TextField::TextField(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled, std::string value)
    : UIElement(position, rotation, scale, visible, disabled),
      _value(value)
{
}

TextField::~TextField()
{
}

void TextField::render()
{
}

std::string TextField::getText()
{
    return _value;
}

void TextField::setText(std::string value)
{
    _value = value;
}

UIElement TextField::toParentObject() const
{
    return ((UIElement)(*this));
}

bool TextField::operator==(const TextField &textField)
{
    return (this->toParentObject() == textField.toParentObject());
}

bool TextField::operator!=(const TextField &textField)
{
    return !((*this) == textField);
}