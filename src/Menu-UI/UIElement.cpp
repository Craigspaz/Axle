#include "Menu-UI/UIElement.h"

UIElement::UIElement(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : _position(position),
      _rotation(rotation),
      _scale(scale),
      _visible(visible),
      _disabled(disabled)
{
}

UIElement::~UIElement()
{
}

void UIElement::render()
{
}

glm::vec3 UIElement::getPosition()
{
    return _position;
}

glm::vec3 UIElement::getScale()
{
    return _scale;
}

glm::vec3 UIElement::getRotation()
{
    return _rotation;
}

bool UIElement::isVisible()
{
    return _visible;
}

bool UIElement::isDisabled()
{
    return _disabled;
}

void UIElement::setPosition(glm::vec3 position)
{
    _position = position;
}

void UIElement::setScale(glm::vec3 scale)
{
    _scale = scale;
}

void UIElement::setRotation(glm::vec3 rotation)
{
    _rotation = rotation;
}

void UIElement::setIsVisible(bool visible)
{
    _visible = visible;
}

void UIElement::setIsDisabled(bool disabled)
{
    _disabled = disabled;
}

bool UIElement::operator==(const UIElement *uielement)
{
    return (this->_position == uielement->_position && this->_rotation == uielement->_rotation && this->_scale == uielement->_scale && this->_visible == uielement->_visible && this->_disabled == uielement->_disabled);
}

bool UIElement::operator!=(const UIElement *uielement)
{
    return !(this == uielement);
}