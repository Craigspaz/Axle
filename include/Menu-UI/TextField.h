#ifndef __TEXTFIELD__
#define __TEXTFIELD__
#include "UIElement.h"
#include <iostream>

class TextField : public UIElement
{
public:
    TextField(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~TextField();

    bool operator==(const TextField *textField);
    bool operator!=(const TextField *textField);

private:
protected:
};

#endif