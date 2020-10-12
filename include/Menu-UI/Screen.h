#ifndef __SCREEN__
#define __SCREEN__
#include "UIElement.h"
#include <iostream>
#include <vector>

class Screen : public UIElement
{
public:
    Screen(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~Screen();

    void render();

    std::vector<UIElement *> getElements();
    void addElement(UIElement *element);
    void removeElement(UIElement *element);

    UIElement toParentObject() const;
    bool operator==(const Screen &screen);
    bool operator!=(const Screen &screen);

private:
    std::vector<UIElement *> _elements;

protected:
};

#endif