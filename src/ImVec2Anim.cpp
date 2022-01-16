#include "ImVec2Anim.h"
#include "Utils.h"

imanim::ImVec2Anim::ImVec2Anim(ImVec2 *pVec2)
    : m_pVec2(pVec2)
{
    // Add dummy start and end key frames
    m_vecKeyValues.push_back(KeyValue(0.0, ImVec2(1, 1)));
    m_vecKeyValues.push_back(KeyValue(1.0, ImVec2(1, 1)));
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

imanim::ImVec2Anim::~ImVec2Anim()
{
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

const ImVec2 &imanim::ImVec2Anim::getEndValue() const
{
    return m_vecKeyValues[m_vecKeyValues.size() - 1].m_vValue;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

const ImVec2 &imanim::ImVec2Anim::getStartValue() const
{
    return m_vecKeyValues[0].m_vValue;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::ImVec2Anim::onStartAnimation()
{
    m_curStartKeyFrame = m_vecKeyValues[0];
    m_curEndKeyFrame = m_vecKeyValues[1];
    m_nEndKeyFrameIndex = 1;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::ImVec2Anim::setEndValue(const ImVec2 &vEndValue)
{
    m_vecKeyValues[m_vecKeyValues.size() - 1] = KeyValue(1.0, vEndValue);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::ImVec2Anim::setKeyValueAt(double dStep, const ImVec2 &vValue)
{
    if ((dStep < 0.0) || (dStep > 1.0))
    {
        // Invalid step
        return;
    }

    // Set or insert the key frame
    for (size_t index = 0; index < m_vecKeyValues.size(); ++index)
    {
        double dCurStep = m_vecKeyValues[index].m_dStep;
        if (imanim::Utils::nearlyEqual(dCurStep, dStep))
        {
            // Replace the current key frame
            m_vecKeyValues[index] = KeyValue(dStep, vValue);
            break;
        }
        if (dCurStep > dStep)
        {
            // Insert the new key frame
            m_vecKeyValues.insert(m_vecKeyValues.begin() + index,
                KeyValue(dStep, vValue));
            break;
        }
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::ImVec2Anim::setStartValue(const ImVec2 &vStartValue)
{
    m_vecKeyValues[0] = KeyValue(0.0, vStartValue);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::ImVec2Anim::updateValueForProgress(double dProgress)
{
    // Make sure that the current start and end frames are valid
    if (dProgress > m_curEndKeyFrame.m_dStep)
    {
        // Find the new start and end frames
        for (size_t index = (m_nEndKeyFrameIndex + 1);
            index < m_vecKeyValues.size(); ++index)
        {
            KeyValue keyValue = m_vecKeyValues[index];
            if (keyValue.m_dStep >= dProgress)
            {
                m_curEndKeyFrame = keyValue;
                m_curStartKeyFrame = m_vecKeyValues[index - 1];
                m_nEndKeyFrameIndex = index;
                break;
            }
        }
    }

    // Calculate the new value
    ImVec2 v;
    v.x = m_curEndKeyFrame.m_vValue.x - m_curStartKeyFrame.m_vValue.x;
    v.y = m_curEndKeyFrame.m_vValue.y - m_curStartKeyFrame.m_vValue.y;
    double dLocalProgress = (dProgress - m_curStartKeyFrame.m_dStep) /
        (m_curEndKeyFrame.m_dStep - m_curStartKeyFrame.m_dStep);
    v.x *= static_cast<float>(dLocalProgress);
    v.y *= static_cast<float>(dLocalProgress);
    ImVec2 vCurValue;
    vCurValue.x = m_curStartKeyFrame.m_vValue.x + v.x;
    vCurValue.y = m_curStartKeyFrame.m_vValue.y + v.y;

    // Update the new value
    m_pVec2->x = vCurValue.x;
    m_pVec2->y = vCurValue.y;
}
