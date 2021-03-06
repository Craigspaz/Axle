#ifndef __SLIDER__
#define __SLIDER__
#include "UIElement.h"
#include <iostream>

class Slider : public UIElement
{
public:
    Slider(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~Slider();

    void render();

    UIElement toParentObject() const;
    bool operator==(const Slider &slider);
    bool operator!=(const Slider &slider);

private:
protected:
};

#endif