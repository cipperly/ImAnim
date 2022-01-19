#include "AbstractAnimation.h"

const imanim::EasingCurve &imanim::AbstractAnimation::getEasingCurve()
    const
{
    return m_easingCurve;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AbstractAnimation::setDuration(float fTimeInSecs)
{
    // TODO: Handle if animation is already in progress
    m_fDurationInSecs = fTimeInSecs;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AbstractAnimation::setEasingCurve(
    imanim::EasingCurve::Type eEasingCurveType, double dAmplitude,
    double dPeriod, double dOvershoot)
{
    m_easingCurve.setType(eEasingCurveType);
    m_easingCurve.setAmplitude(dAmplitude);
    m_easingCurve.setPeriod(dPeriod);
    m_easingCurve.setOvershoot(dOvershoot);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AbstractAnimation::setLoopCount(int nLoopCount)
{
    m_nLoopCount = nLoopCount;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AbstractAnimation::start()
{
    if (m_nLoopCount == 0)
    {
        // No loop count, so ignore start
        return;
    }
    if (m_eAnimationState == State::Running)
    {
        // Animation is already in progress
        return;
    }

    m_eAnimationState = State::Running;
    m_startTime = std::chrono::high_resolution_clock::now();
    m_nCurrentLoop = 0;

    onStartAnimation();
    updateValueForProgress(m_easingCurve.calculateValueForProgress(0.0));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AbstractAnimation::stop()
{
    if (m_eAnimationState != State::Stopped)
    {
        m_eAnimationState = State::Stopped;
        m_nCurrentLoop = 0;
        onStopAnimation();
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AbstractAnimation::update()
{
    if (m_eAnimationState != State::Running)
    {
        return;
    }

    // Calculate the amount of time we've been fading
    std::chrono::duration<float> duration =
        std::chrono::high_resolution_clock::now() - m_startTime;
    float fDurationInSecs = duration.count();

    if (fDurationInSecs >= m_fDurationInSecs)
    {
        // Last animation update
        updateValueForProgress(m_easingCurve.calculateValueForProgress(1.0));
        m_nCurrentLoop++;
        if ((m_nCurrentLoop >= m_nLoopCount) && (m_nLoopCount >= 0))
        {
            // This animation is finished
            m_eAnimationState = State::Stopped;
            m_nCurrentLoop = 0;
            onStopAnimation();
            return;
        }
        m_startTime = std::chrono::high_resolution_clock::now();
        onStartAnimation();
    }
    else
    {
        // Calculate the current progress
        double t = 1.0 - ((m_fDurationInSecs - fDurationInSecs) /
            m_fDurationInSecs);
        updateValueForProgress(m_easingCurve.calculateValueForProgress(t));
    }
}
