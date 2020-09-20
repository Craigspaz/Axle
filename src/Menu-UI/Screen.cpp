#include "Menu-UI/Screen.h"

Screen::Screen(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Screen::~Screen()
{
}

bool Screen::operator==(const Screen *screen)
{
    return (((UIElement *)this) == ((UIElement *)screen));
}

bool Screen::operator!=(const Screen *screen)
{
    return !(this == screen);
}