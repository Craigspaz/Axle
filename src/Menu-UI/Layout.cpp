#include "Menu-UI/Layout.h"

Layout::Layout(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Layout::~Layout()
{
}

void Layout::render()
{
}

std::vector<UIElement *> Layout::getElements()
{
    return _elements;
}

void Layout::addElement(UIElement *element)
{
    _elements.push_back(element);
}

void Layout::removeOption(UIElement *element)
{
    for (int i = 0; i < _elements.size(); i++)
    {
        if (_elements[i] == element)
        {
            _elements.erase(_elements.begin() + i);
            break;
        }
    }
}

bool Layout::operator==(const Layout *layout)
{
    return (this->_position == layout->_position && this->_rotation == layout->_rotation && this->_scale == layout->_scale && this->_visible == layout->_visible && this->_disabled == layout->_disabled && this->_elements.size() == layout->_elements.size());
}