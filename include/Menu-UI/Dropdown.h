#ifndef __DROPDOWN__
#define __DROPDOWN__
#include "UIElement.h"
#include <iostream>
#include <string>
#include <vector>

class DropDown : public UIElement
{
public:
    DropDown(std::vector<std::string> options, int numberOfOptions, glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~DropDown();

    void render();

    std::vector<std::string> getOptions();
    void addOption(std::string option);
    void removeOption(std::string option);
    void setOptions(std::vector<std::string> options);

    std::string getSelectedValue();
    std::string getDefaultValue();
    void setDefaultOption(int option);
    void setSelectedOption(int option);
    int getSelectedOption();
    int getDefaultOption();

    UIElement toParentObject() const;
    bool operator==(const DropDown &dropDown);
    bool operator!=(const DropDown &dropDown);

private:
    std::vector<std::string> _options; // Array of options
    int _selected;
    int _default;
protected:
};

#endif