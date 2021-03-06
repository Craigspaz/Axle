#include "Menu-UI/ProgressBar.h"

ProgressBar::ProgressBar(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale, bool visible, bool disabled)
    : UIElement(position, rotation, scale, visible, disabled),
      _progress(0.0f)
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::render()
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

UIElement ProgressBar::toParentObject() const
{
    return ((UIElement)(*this));
}

bool ProgressBar::operator==(const ProgressBar &progressBar)
{
    return (this->_progress == progressBar._progress && this->toParentObject() == progressBar.toParentObject());
}

bool ProgressBar::operator!=(const ProgressBar &progressBar)
{
    return !((*this) == progressBar);
}