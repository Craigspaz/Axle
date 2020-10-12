#ifndef __TEXTFIELD__
#define __TEXTFIELD__
#include "UIElement.h"
#include <iostream>
#include <string>

class TextField : public UIElement
{
public:
    TextField(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false, std::string value = "");
    ~TextField();

    void render();

    std::string getText();
    void setText(std::string value);

    UIElement toParentObject() const;
    bool operator==(const TextField &textField);
    bool operator!=(const TextField &textField);

private:
    std::string _value;

protected:
};

#endif