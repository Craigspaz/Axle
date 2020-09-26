#include "Menu-UI/Image.h"

Image::Image(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Image::~Image()
{
}

UIElement Image::toParentObject() const
{
    return ((UIElement)(*this));
}

bool Image::operator==(const Image &image)
{
    return (this->toParentObject() == image.toParentObject());
}

bool Image::operator!=(const Image &image)
{
    return !((*this) == image);
}