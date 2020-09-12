#ifndef __BUTTON__
#define __BUTTON__
#include "UIElement.h"
#include <iostream>
#include <string>

class Button: public UIElement
{
    public:
        Button(std::string text, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
        ~Button();

        void render();

        void press();
    private:
        std::string _text;
    protected:
};

#endif