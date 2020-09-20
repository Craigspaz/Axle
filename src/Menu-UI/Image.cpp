#include "Menu-UI/Image.h"

Image::Image(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Image::~Image()
{
}

bool Image::operator==(const Image *image)
{
    return (((UIElement *)this) == ((UIElement *)image));
}

bool Image::operator!=(const Image *image)
{
    return !(this == image);
}