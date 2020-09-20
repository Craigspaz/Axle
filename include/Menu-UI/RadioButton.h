#ifndef __RADIOBUTTON__
#define __RADIOBUTTON__
#include "UIElement.h"
#include <iostream>

class RadioButton : public UIElement
{
public:
    RadioButton(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~RadioButton();

    bool operator==(const RadioButton &radioButton);
    bool operator!=(const RadioButton &radioButton);

private:
protected:
};

#endif