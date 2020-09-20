#include "Menu-UI/Slider.h"

Slider::Slider(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Slider::~Slider()
{
}

bool Slider::operator==(const Slider &slider)
{
    return (((UIElement)(*this)) == ((UIElement)slider));
}

bool Slider::operator!=(const Slider &slider)
{
    return !((*this) == slider);
}