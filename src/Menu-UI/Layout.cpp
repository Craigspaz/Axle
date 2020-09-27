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

void Layout::removeElement(UIElement *element)
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

UIElement Layout::toParentObject() const
{
    return ((UIElement)(*this));
}

bool Layout::operator==(const Layout &layout)
{
    return (this->_elements.size() == layout._elements.size() && this->toParentObject() == layout.toParentObject());
}

bool Layout::operator!=(const Layout &layout)
{
    return !((*this) == layout);
}