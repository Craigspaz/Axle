#include "Menu-UI/TextField.h"

TextField::TextField(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

TextField::~TextField()
{
}

void TextField::render()
{
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