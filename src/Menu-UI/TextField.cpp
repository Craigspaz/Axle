#include "Menu-UI/TextField.h"

TextField::TextField(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

TextField::~TextField()
{
}

bool TextField::operator==(const TextField &textField)
{
    return (((UIElement)(*this)) == ((UIElement)textField));
}

bool TextField::operator!=(const TextField &textField)
{
    return !((*this) == textField);
}