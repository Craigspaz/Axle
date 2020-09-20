#include "Menu-UI/RadioButton.h"

RadioButton::RadioButton(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

RadioButton::~RadioButton()
{
}

bool RadioButton::operator==(const RadioButton *radioButton)
{
    return (((UIElement *)this) == ((UIElement *)radioButton));
}

bool RadioButton::operator!=(const RadioButton *radioButton)
{
    return !(this == radioButton);
}