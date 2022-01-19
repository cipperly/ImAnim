#include "SequentialAnimationGroup.h"

float imanim::SequentialAnimationGroup::getDuration() const
{
    float fDurationInSecs = 0.0F;

    for (const auto &pAnimation : m_vecAnimations)
    {
        int nLoopCount = pAnimation->getLoopCount();
        float fCurDurationInSecs = pAnimation->getDuration();
        if ((nLoopCount < 0) || (fCurDurationInSecs < 0.0F))
        {
            // The animation has an infinite time, so set the duration to -1
            // and break loop
            fDurationInSecs = -1.0F;
            break;
        }

        fDurationInSecs += (static_cast<float>(nLoopCount) *
            fCurDurationInSecs);
    }

    return fDurationInSecs;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::SequentialAnimationGroup::onStartAnimation()
{
    if (m_vecAnimations.empty())
    {
        // No animations so stop
        m_eAnimationState = State::Stopped;
        m_nCurrentLoop = 0;
        return;
    }

    m_nIndexOfCurrentAnimation = 0;
    m_pCurrentAnimation = m_vecAnimations[0];
    m_pCurrentAnimation->start();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::SequentialAnimationGroup::onStopAnimation()
{
    if (m_pCurrentAnimation != nullptr)
    {
        m_pCurrentAnimation->stop();
    }
    m_nIndexOfCurrentAnimation = 0;
    m_pCurrentAnimation = nullptr;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::SequentialAnimationGroup::update()
{
    if ((m_eAnimationState != State::Running) ||
        (m_pCurrentAnimation == nullptr))
    {
        return;
    }

    // Update the current animation
    m_pCurrentAnimation->update();

    if (m_pCurrentAnimation->getState() == State::Stopped)
    {
        // Move to the next animation in the sequence
        m_nIndexOfCurrentAnimation++;
        if (m_nIndexOfCurrentAnimation >= m_vecAnimations.size())
        {
            // Increment the loop
            m_nCurrentLoop++;
            m_nIndexOfCurrentAnimation = 0;
            if ((m_nCurrentLoop >= m_nLoopCount) && (m_nLoopCount >= 0))
            {
                // This animation is finished
                m_eAnimationState = State::Stopped;
                m_nCurrentLoop = 0;
                m_pCurrentAnimation = nullptr;
                return;
            }
        }
        m_pCurrentAnimation = m_vecAnimations[m_nIndexOfCurrentAnimation];
        m_pCurrentAnimation->start();
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::SequentialAnimationGroup::updateValueForProgress(
    [[maybe_unused]] double dProgress)
{
}
