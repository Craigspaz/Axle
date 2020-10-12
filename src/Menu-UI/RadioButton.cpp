#include "Menu-UI/RadioButton.h"

RadioButton::RadioButton(std::vector<std::string> options, int numberOfOptions, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
      _options(options),
      _default(0),
      _selected(0)
{
}

void RadioButton::render()
{
}

std::vector<std::string> RadioButton::getOptions()
{
    return _options;
}

void RadioButton::addOption(std::string option)
{
    _options.push_back(option);
}

void RadioButton::removeOption(std::string option)
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

void RadioButton::setOptions(std::vector<std::string> options)
{
    _options = options;
}

std::string RadioButton::getSelectedValue()
{
    return _options[_selected];
}

std::string RadioButton::getDefaultValue()
{
    return _options[_default];
}

void RadioButton::setDefaultOption(int option)
{
    _default = option;
}

void RadioButton::setSelectedOption(int option)
{
    _selected = option;
}

int RadioButton::getSelectedOption()
{
    return _selected;
}

int RadioButton::getDefaultOption()
{
    return _default;
}

RadioButton::~RadioButton()
{
}

UIElement RadioButton::toParentObject() const
{
    return ((UIElement)(*this));
}

bool RadioButton::operator==(const RadioButton &radioButton)
{
    bool part1 = (this->_default == radioButton._default && this->_selected == radioButton._selected && this->_options.size() == radioButton._options.size() && this->toParentObject() == radioButton.toParentObject());
    bool elements = false;

    if (part1)
    {
        bool brokeOut = false;
        for (int i = 0; i < this->_options.size(); i++)
        {
            if (this->_options[i] != radioButton._options[i])
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

bool RadioButton::operator!=(const RadioButton &radioButton)
{
    return !((*this) == radioButton);
}