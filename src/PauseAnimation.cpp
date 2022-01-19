#include "PauseAnimation.h"

imanim::PauseAnimation::PauseAnimation(float fDurationInSecs)
{
    setDuration(fDurationInSecs);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::PauseAnimation::updateValueForProgress(double dProgress)
{
    // Do nothing
}
