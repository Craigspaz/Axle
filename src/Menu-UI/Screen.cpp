#include "Menu-UI/Screen.h"

Screen::Screen(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Screen::~Screen()
{
}

void Screen::render()
{
}

std::vector<UIElement *> Screen::getElements()
{
    return _elements;
}

void Screen::addElement(UIElement *element)
{
    _elements.push_back(element);
}

void Screen::removeElement(UIElement *element)
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

UIElement Screen::toParentObject() const
{
    return ((UIElement)(*this));
}

bool Screen::operator==(const Screen &screen)
{
    return (this->toParentObject() == screen.toParentObject());
}

bool Screen::operator!=(const Screen &screen)
{
    return !((*this) == screen);
}