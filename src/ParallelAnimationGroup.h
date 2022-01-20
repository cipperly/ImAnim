#pragma once

#include "AnimationGroup.h"

namespace imanim
{

/**
 * @brief A group of animations that are run in parallel.
 */
class ParallelAnimationGroup : public AnimationGroup
{
public:

    /**
     * Retrieves the duration of this animation.  This is the duration for a
     * single loop of this group, so it is the maximum duration from the
     * animations in this group since the animation runs in parallel.
     * @return this animation's duration in seconds; will return -1 if this
     *      group contains an animation with a loop count of -1.
     */
    [[nodiscard]] float getDuration() const override;

    /**
     * Performs an update of this animation
     */
    void update() override;

protected:

    /**
     * Extending classes should override to provide any extra handling at the
     * start of animation
     */
    void onStartAnimation() override;

    /**
     * Extending classes should override to provide extra handling at the stop
     * of animation
     */
    void onStopAnimation() override;

    /**
     * @brief Extending classes should update their value being interpolated
     * based on the specified current progress
     * @param dProgress the current progress for this animation
     */
    void updateValueForProgress(double dProgress) override;
};

} // namespace imanim
