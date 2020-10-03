#include "Menu-UI/Dropdown.h"

DropDown::DropDown(std::vector<std::string> options, int numberOfOptions, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
      _options(options),
      _default(0),
      _selected(0)
{
}

DropDown::~DropDown()
{
}

void DropDown::render()
{
}

std::vector<std::string> DropDown::getOptions()
{
    return _options;
}

void DropDown::addOption(std::string option)
{
    _options.push_back(option);
}

void DropDown::removeOption(std::string option)
{
    for (int i = 0; i < _options.size(); i++)
    {
        if (_options[i].compare(option) == 0)
        {
            _options.erase(_options.begin() + i);
            break;
        }
    }
}

void DropDown::setOptions(std::vector<std::string> options)
{
    _options = options;
}

std::string DropDown::getSelectedValue()
{
    return _options[_selected];
}

std::string DropDown::getDefaultValue()
{
    return _options[_default];
}

void DropDown::setDefaultOption(int option)
{
    _default = option;
}

void DropDown::setSelectedOption(int option)
{
    _selected = option;
}

int DropDown::getSelectedOption()
{
    return _selected;
}

int DropDown::getDefaultOption()
{
    return _default;
}

UIElement DropDown::toParentObject() const
{
    return ((UIElement)(*this));
}

bool DropDown::operator==(const DropDown &dropDown)
{
    bool part1 = (this->_default == dropDown._default && this->_selected == dropDown._selected && this->_options.size() == dropDown._options.size() && this->toParentObject() == dropDown.toParentObject());
    bool elements = false;

    if (part1)
    {
        bool brokeOut = false;
        for (int i = 0; i < this->_options.size(); i++)
        {
            if (this->_options[i] != dropDown._options[i])
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

bool DropDown::operator!=(const DropDown &dropDown)
{
    return !((*this) == dropDown);
}