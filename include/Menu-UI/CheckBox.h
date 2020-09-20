#ifndef __CHECKBOX__
#define __CHECKBOX__
#include "UIElement.h"
#include <iostream>
#include <string>

class CheckBox : public UIElement
{
public:
    CheckBox(bool currentState, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~CheckBox();

    void render();

    bool isChecked();
    void setIsChecked(bool state);
    bool operator==(const CheckBox *checkBox);
    bool operator!=(const CheckBox *checkBox);

private:
    bool _currentState; // true is checked false is unchecked
protected:
};

#endif