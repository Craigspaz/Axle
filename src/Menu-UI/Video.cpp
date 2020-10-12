#include "Menu-UI/Video.h"

Video::Video(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Video::~Video()
{
}

void Video::render()
{
}

UIElement Video::toParentObject() const
{
    return ((UIElement)(*this));
}

bool Video::operator==(const Video &video)
{
    return (this->toParentObject() == video.toParentObject());
}

bool Video::operator!=(const Video &video)
{
    return !((*this) == video);
}