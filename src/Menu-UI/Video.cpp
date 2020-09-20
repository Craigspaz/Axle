#include "Menu-UI/Video.h"

Video::Video(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
}

Video::~Video()
{
}

bool Video::operator==(const Video *video)
{
    return (((UIElement *)this) == ((UIElement *)video));
}

bool Video::operator!=(const Video *video)
{
    return !(this == video);
}