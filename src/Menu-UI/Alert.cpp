#include "Menu-UI/Alert.h"

Alert::Alert(std::string message, std::string confirmButtonText, std::string cancelButtonText, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
    // TODO: Update Position and Labels
    _confirmButton = new Button(confirmButtonText, position, rotation,scale, visible, disabled);
    _cancelButton = new Button(cancelButtonText, position, rotation, scale, visible, disabled);
    _message = new Label(message, position, rotation, scale, visible, disabled);
}

Alert::~Alert()
{
    delete _confirmButton;
    delete _cancelButton;
    delete _message;
}

void Alert::render()
{
    
}