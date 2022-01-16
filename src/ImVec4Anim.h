#pragma once

#include "AbstractAnimation.h"
#include "imgui.h"
#include <vector>

namespace imanim
{

/**
 * @brief Performs an animation using a ImVec4 object
 */
class ImVec4Anim : public imanim::AbstractAnimation
{
public:

    /**
     * ImVec4Anim constructor
     * @param pVec4 the ImVec4 that this animation is for
     */
    explicit ImVec4Anim(ImVec4 *pVec4);

    /**
     * ImVec4Anim destructor
     */
    virtual ~ImVec4Anim();

    class KeyValue
    {
    public:

        KeyValue()
            : m_dStep(0.0)
        {}
        explicit KeyValue(double dStep, ImVec4 vValue)
            : m_dStep(dStep)
            , m_vValue(vValue)
        {}

        /// the step for this key frame; must be in the range of 0 to 1
        double m_dStep;

        /// the value for this key frame
        ImVec4 m_vValue;
    };

    /**
     * @brief Returns the ending animation value
     * @return this animation's ending value
     */
    const ImVec4 &getEndValue() const;

    /**
     * @brief Returns the starting animation value
     * @return this animation's starting value
     */
    const ImVec4 &getStartValue() const;

    /**
     * @brief Sets the ending animation value
     * @param vEndValue this animation's ending value
     */
    void setEndValue(const ImVec4 &vEndValue);

    /**
     * Sets a key frame at the specified step with the specified value
     * @param dStep the step for the frame; must be in the range 0 to 1
     * @param vValue the value for the animation key frame
     */
    void setKeyValueAt(double dStep, const ImVec4 &vValue);

    /**
     * @brief Sets the starting animation value
     * @param vStartValue this animation's starting value
     */
    void setStartValue(const ImVec4 &vStartValue);

protected:

    /**
     * Extending classes should override to provide any extra handling at the
     * start of animation
     */
    void onStartAnimation() override;

    /**
     * @brief Extending classes should update their value being interpolated
     * based on the specified current progress
     * @param dProgress the current progress for this animation
     */
    void updateValueForProgress(double dProgress) override;

    /// the ImVec4 being animated
    ImVec4 *m_pVec4;

    /// the list of key values (frames) for this animation; it will always have
    /// a minimum of two values: the start and end frames
    std::vector<KeyValue> m_vecKeyValues;

    /// the key value for the start of the current frame
    KeyValue m_curStartKeyFrame;

    /// the key value for the end of the current frame
    KeyValue m_curEndKeyFrame;

    /// the index of the key value in m_vecKeyValues for the end of the current
    /// frame
    size_t m_nEndKeyFrameIndex { 0 };
};

} // namespace imanim
