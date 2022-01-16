#pragma once

#include "EasingCurve.h"
#include <chrono>

namespace imanim
{

/**
 * @brief The base for all animations
 */
class AbstractAnimation
{
public:

    /**
     * AbstractAnimation constructor
     */
    AbstractAnimation() = default;

    /**
     * AbstractAnimation destructor
     */
    virtual ~AbstractAnimation() = default;

    enum class State
    {
        Stopped,
        Running,
    };

    /**
     * Returns the current loop of this animation; once the animation completes
     * its duration, this count will be incremented.  If the loop count is 1,
     * this will always be 0.
     * @return the current loop of this animation
     */
    [[nodiscard]] int getCurrentLoop() const
    { return m_nCurrentLoop; }

    /**
     * Retrieves the duration of this animation
     * @return this animation's duration in seconds
     */
    [[nodiscard]] float getDuration() const
    { return m_fDurationInSecs; }

    /**
     * Retrieves the easing curve being used for this animation
     * @return this animation's easing curve
     */
    [[nodiscard]] const imanim::EasingCurve &getEasingCurve() const;

    /**
     * Returns the loop count for this animation, which is the numer of loops
     * that this animation should loop before stopping.  A value of 0 indicates
     * that this animation will not run at all; a value of < 0 indicates that
     * this animation will loop forever.
     * @return this animation's loop count
     */
    [[nodiscard]] int getLoopCount() const
    { return m_nLoopCount; }

    /**
     * Returns the state of this animate
     * @return this animation's state
     */
    [[nodiscard]] State getState() const
    { return m_eAnimationState; }

    /**
     * Sets the duration for this animation
     * @param fTimeInSecs the duration time in seconds
     */
    void setDuration(float fTimeInSecs);

    /**
     * Sets the easing curve equation used by this animation
     * @param eEasingCurveType the type of easing curve
     * @param dAmplitude the amplitude for the easing curve.  This is only
     *      applicable to bounce and elastic curves and will be ignored for
     *      other curves.  It is the amplitude of the bounce or elastic
     *      (spring) effect.  Values < 0.0 are invalid and will be ignored.
     * @param dPeriod  the period for the easing curve, where a small value will
     *      give a high frequency of the curve and a large period will give it a
     *      small frequency.  This is only applicable to elastic curves and will
     *      be ignored for other curves.  Values < 0.0 are invalid and will be
     *      ignored.
     * @param dOvershoot the overshoot amount where higher means greater
     *      overshoot (0 produces cubic easing with no overshoot, and the
     *      default value of 1.70158 produces an overshoot of 10 percent).
     *      This is only applicable to back curves and will be ignored for other
     *      curves.  Values < 0.0 are invalid and will be ignored.
     */
    void setEasingCurve(imanim::EasingCurve::Type eEasingCurveType,
        double dAmplitude = 1.0, double dPeriod = 0.3,
        double dOvershoot = 1.70158);

    /**
     * Sets the loop count for this animation, which is the numer of loops that
     * this animation should loop before stopping.  A value of 0 indicates that
     * this animation will not run at all; a value of -1 indicates that this
     * animation will loop forever.
     * @param nLoopCount this animation's loop count
     */
    void setLoopCount(int nLoopCount);

    /**
     * Starts this animation
     */
    void start();

    /**
     * Stops this animation.
     */
    void stop();

    /**
     * Performs an update of this animation
     */
    void update();

protected:

    /**
     * Extending classes should override to provide any extra handling at the
     * start of animation
     */
    virtual void onStartAnimation() {}

    /**
     * @brief Extending classes should update their value being interpolated
     * based on the specified current progress
     * @param dProgress the current progress for this animation
     */
    virtual void updateValueForProgress(double dProgress) = 0;

private:

    /// the easing curve used for this animation
    imanim::EasingCurve m_easingCurve;

    /// the duration for this animation in seconds
    float m_fDurationInSecs { 0.0F };

    /// the loop count for this animation, which is the numer of loops that this
    /// animation should loop before stopping.  A value of 0 indicates that this
    /// animation will not run at all; a value of -1 indicates that this
    /// animation will loop forever.
    int m_nLoopCount { 1 };

    /// the current loop of this animation; once the animation completes its
    /// duration, this count will be incremented.  If the loop count is 1, this
    /// will always be 0.
    int m_nCurrentLoop { 0 };

    /// The time stamp upon starting animation
    std::chrono::steady_clock::time_point m_startTime;

    /// the state of this animation
    State m_eAnimationState { State::Stopped };
};

} // namespace imanim
