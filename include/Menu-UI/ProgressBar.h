#ifndef __PROGRESSBAR__
#define __PROGRESSBAR__
#include "UIElement.h"
#include <iostream>

class ProgressBar : public UIElement
{
public:
    ProgressBar(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible = true, bool disabled = false);
    ~ProgressBar();

    void render();

    float getProgress();
    void setProgress(float progress);

    UIElement toParentObject() const;
    bool operator==(const ProgressBar &progressBar);
    bool operator!=(const ProgressBar &progressBar);

private:
    float _progress; // As Percent
protected:
};

#endif