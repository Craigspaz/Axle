#include "Menu-UI/Label.h"

Label::Label(std::string text, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
    _text(text)
{
}

Label::~Label()
{
}

void Label::render()
{

}

std::string Label::getText()
{
    return _text;
}

void Label::setText(std::string text)
{
    _text = text;
}