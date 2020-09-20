#ifndef __VIDEO__
#define __VIDEO__
#include "UIElement.h"
#include <iostream>

class Video : public UIElement
{
public:
    Video(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~Video();

    bool operator==(const Video &video);
    bool operator!=(const Video &video);

private:
protected:
};

#endif