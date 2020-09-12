#include "Menu-UI/Alert.h"

Alert::Alert(std::string message, std::string confirmButtonText, std::string cancelButtonText, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled)
{
    
}

Alert::~Alert()
{
}

void Alert::render()
{
    
}