#ifndef __ALERT__
#define __ALERT__
#include "UIElement.h"
#include "Button.h"
#include "Label.h"
#include <iostream>
#include <string>

class Alert: public UIElement
{
    public:
        Alert(std::string message, std::string confirmButtonText, std::string cancelButtonText, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
        ~Alert();

        void render();

    private:
        Button* _confirmButton;
        Button* _cancelButton;
        Label* _message;
    protected:
};

#endif