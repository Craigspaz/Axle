#ifndef __IMAGE__
#define __IMAGE__
#include "UIElement.h"
#include <iostream>

class Image : public UIElement
{
public:
    Image(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~Image();

    UIElement toParentObject() const;
    bool operator==(const Image &image);
    bool operator!=(const Image &image);

private:
protected:
};

#endif