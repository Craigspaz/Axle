#include "Menu-UI/ProgressBar.h"

ProgressBar::ProgressBar(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
      _progress(0.0f)
{
}

ProgressBar::~ProgressBar()
{
}

float ProgressBar::getProgress()
{
    return _progress;
}

void ProgressBar::setProgress(float progress)
{
    _progress = progress;
}

bool ProgressBar::operator==(const ProgressBar *progressBar)
{
    return (this->_progress == progressBar->_progress && ((UIElement *)this) == ((UIElement *)progressBar));
}

bool ProgressBar::operator!=(const ProgressBar *progressBar)
{
    return !(this == progressBar);
}