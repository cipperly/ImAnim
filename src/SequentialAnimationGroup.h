#pragma once

#include "AnimationGroup.h"

namespace imanim
{

/**
 * @brief A group of animations that are run sequentially.  Note that if you add
 * an animation to this group that has a loop count of -1, then this sequence
 * will never progress past that animation.
 */
class SequentialAnimationGroup : public AnimationGroup
{
public:

    /**
     * Retrieves the duration of this animation.  This is the duration for a
     * single loop of this group.
     * @return this animation's duration in seconds; will return -1 if this
     *      group contains an animation with a loop count of -1.
     */
    [[nodiscard]] float getDuration() const override;

    /**
     * Performs an update of this animation
     */
    void update() override;

    /**
     * Returns the current animation being run
     * @return the current animation; nullptr if this animation is stopped
     */
    [[nodiscard]] AbstractAnimation *getCurrentAnimation() const
    { return m_pCurrentAnimation; }

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

private:

    /// the current animation being run in this group of animations
    AbstractAnimation *m_pCurrentAnimation { nullptr };

    /// the index of the current animation being run in this group of animations
    size_t m_nIndexOfCurrentAnimation { 0 };
};

} // namespace imanim
