#include "Menu-UI/CheckBox.h"

CheckBox::CheckBox(bool currentState, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
      _currentState(currentState)
{
}

CheckBox::~CheckBox()
{
}

void CheckBox::render()
{
}

bool CheckBox::isChecked()
{
    return _currentState;
}
void CheckBox::setIsChecked(bool state)
{
    _currentState = state;
}

UIElement CheckBox::toParentObject() const
{
    return ((UIElement)(*this));
}

bool CheckBox::operator==(const CheckBox &checkBox)
{
    return (this->_currentState == checkBox._currentState && this->toParentObject() == checkBox.toParentObject());
}

bool CheckBox::operator!=(const CheckBox &checkBox)
{
    return !((*this) == checkBox);
}