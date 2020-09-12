#include "Menu-UI/Dropdown.h"

DropDown::DropDown(std::vector<std::string> options, int numberOfOptions, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
      _options(options)
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
    // TODO
}

void DropDown::setOptions(std::vector<std::string> options)
{
    _options = options;
}