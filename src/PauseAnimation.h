#pragma once

#include "AbstractAnimation.h"

namespace imanim
{

/**
 * @brief An animation that acts like a pause and does nothing during its
 * duration
 */
class PauseAnimation : public imanim::AbstractAnimation
{
public:

    /**
     * PauseAnimation constructor
     */
    PauseAnimation() = default;

    /**
     * PauseAnimation constructor
     * @param fDurationInSecs the duration for this pause in seconds
     */
    explicit PauseAnimation(float fDurationInSecs);

    /**
     * PauseAnimation destructor
     */
    virtual ~PauseAnimation() = default;

protected:

    /**
     * @brief Extending classes should update their value being interpolated
     * based on the specified current progress
     * @param dProgress the current progress for this animation
     */
    void updateValueForProgress(double dProgress) override;
};

} // namespace imanim
