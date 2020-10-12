#ifndef __LAYOUT__
#define __LAYOUT__
#include "UIElement.h"
#include <iostream>
#include <string>
#include <vector>

class Layout : public UIElement
{
public:
    Layout(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~Layout();

    void render();

    std::vector<UIElement *> getElements();
    void addElement(UIElement *element);
    void removeElement(UIElement *element);

    UIElement toParentObject() const;
    bool operator==(const Layout &layout);
    bool operator!=(const Layout &layout);

private:
    std::vector<UIElement *> _elements;

protected:
};

#endif