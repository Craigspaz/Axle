#ifndef __LABEL__
#define __LABEL__
#include "UIElement.h"
#include <iostream>
#include <string>

class Label : public UIElement
{
public:
    Label(std::string text, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~Label();

    void render();

    std::string getText();
    void setText(std::string text);
    bool operator==(const Label &label);
    bool operator!=(const Label &label);

private:
    std::string _text;

protected:
};

#endif