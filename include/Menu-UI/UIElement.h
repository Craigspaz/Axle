#ifndef __UIELEMENT__
#define __UIELEMENT__
#include <glm/glm.hpp>

class UIElement
{
public:
    UIElement(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    virtual ~UIElement();

    virtual void render();

    glm::vec3 getPosition();
    glm::vec3 getScale();
    glm::vec3 getRotation();
    bool isVisible();
    bool isDisabled();
    void setPosition(glm::vec3 position);
    void setScale(glm::vec3 scale);
    void setRotation(glm::vec3 rotation);
    void setIsVisible(bool visible);
    void setIsDisabled(bool disabled);

    bool operator==(const UIElement &uielement);
    bool operator!=(const UIElement &uielement);

private:
protected:
    glm::vec3 _position;
    glm::vec3 _scale;
    glm::vec3 _rotation;

    bool _visible;
    bool _disabled;
};

#endif