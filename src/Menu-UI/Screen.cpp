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
    bool part1 = (this->_elements.size() == screen._elements.size() && this->toParentObject() == screen.toParentObject());
    bool elements = false;

    if (part1)
    {
        bool brokeOut = false;
        for (int i = 0; i < this->_elements.size(); i++)
        {
            if (this->_elements[i] != screen._elements[i])
            {
                brokeOut = true;
                break;
            }
        }
        if (!brokeOut)
        {
            elements = true;
        }
    }

    return part1 && elements;
}

bool Screen::operator!=(const Screen &screen)
{
    return !((*this) == screen);
}