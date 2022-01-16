#pragma once

namespace imanim
{

/**
 * @brief Provides easing curves for animation
 */
class EasingCurve
{
public:

    enum class Type : int
    {
        Linear = 0,
        InQuad, OutQuad, InOutQuad, OutInQuad,
        InCubic, OutCubic, InOutCubic, OutInCubic,
        InQuart, OutQuart, InOutQuart, OutInQuart,
        InQuint, OutQuint, InOutQuint, OutInQuint,
        InSine, OutSine, InOutSine, OutInSine,
        InExpo, OutExpo, InOutExpo, OutInExpo,
        InCirc, OutCirc, InOutCirc, OutInCirc,
        InElastic, OutElastic, InOutElastic, OutInElastic,
        InBack, OutBack, InOutBack, OutInBack,
        InBounce, OutBounce, InOutBounce, OutInBounce,
    };

    static constexpr const char * const TYPE_STRINGS[] {"Linear",
        "InQuad", "OutQuad", "InOutQuad", "OutInQuad",
        "InCubic", "OutCubic", "InOutCubic", "OutInCubic",
        "InQuart", "OutQuart", "InOutQuart", "OutInQuart",
        "InQuint", "OutQuint", "InOutQuint", "OutInQuint",
        "InSine", "OutSine", "InOutSine", "OutInSine",
        "InExpo", "OutExpo", "InOutExpo", "OutInExpo",
        "InCirc", "OutCirc", "InOutCirc", "OutInCirc",
        "InElastic", "OutElastic", "InOutElastic", "OutInElastic",
        "InBack", "OutBack", "InOutBack", "OutInBack",
        "InBounce", "OutBounce", "InOutBounce", "OutInBounce"};

    /**
     * EasingCurve constructor
     * @param eType the type of this easing curve
     */
    explicit EasingCurve(EasingCurve::Type eType = EasingCurve::Type::Linear);

    /**
     * @brief Calculates the effective progress for the easing curve at the
     * specified progress
     * @param dProgress the progress; must be between 0.0 and 1.0
     * @return the effective progress, which can be outside the 0.0 and 1.0
     *      bounds
     */
    [[nodiscard]] double calculateValueForProgress(double dProgress);

    /**
     * @brief Returns the amplitude for this easing curve.  This is only
     * applicable to bounce and elastic curves and will be ignored for other
     * curves.  It is the amplitude of the bounce or elastic (spring) effect.
     * @return this easing curve's amplitude
     */
    [[nodiscard]] double getAmplitude() const;

    /**
     * @brief Returns the overshoot amount where higher means greater overshoot
     * (0 produces cubic easing with no overshoot, and the default value of
     * 1.70158 produces an overshoot of 10 percent).  This is only applicable
     * to back curves and will be ignored for other curves.
     * @return this easing curve's overshoot
     */
    [[nodiscard]] double getOvershoot() const;

    /**
     * @brief Returns the period for this easing curve, where a small value will
     * give a high frequency of the curve and a large period will give it a
     * small frequency.  This is only applicable to elastic curves and will be
     * ignored for other curves.
     * @return this easing curve's period
     */
    [[nodiscard]] double getPeriod() const;

    /**
     * @brief Returns the type of this easing curve
     * @return this easing curve's equation type
     */
    [[nodiscard]] EasingCurve::Type getType() const;

    /**
     * @brief Sets the amplitude for this easing curve.  This is only
     * applicable to bounce and elastic curves and will be ignored for other
     * curves.  It is the amplitude of the bounce or elastic (spring) effect.
     * @param dAmplitude this easing curve's amplitude; values < 0.0 are invalid
     *      and will be ignored
     */
    void setAmplitude(double dAmplitude);

    /**
     * @brief Sets the overshoot amount where higher means greater overshoot
     * (0 produces cubic easing with no overshoot, and the default value of
     * 1.70158 produces an overshoot of 10 percent).  This is only applicable
     * to back curves and will be ignored for other curves.
     * @param dOvershoot this easing curve's overshoot; values < 0.0 are invalid
     *      and will be ignored
     */
    void setOvershoot(double dOvershoot);

    /**
     * @brief Sets the period for this easing curve, where a small value will
     * give a high frequency of the curve and a large period will give it a
     * small frequency.  This is only applicable to elastic curves and will be
     * ignored for other curves.
     * @param dPeriod this easing curve's period; values < 0.0 are invalid and
     *      will be ignored
     */
    void setPeriod(double dPeriod);

    /**
     * @brief Sets the type of this easing curve
     * @param eType this easing curve's equation type
     */
    void setType(EasingCurve::Type eType);

private:

    /// the type of this easing curve
    EasingCurve::Type m_eType;

    /// the amplitude for this easing curve
    double m_dAmplitude { 1.0 };

    /// the overshoot for this easing curve
    double m_dOvershoot  { 1.70158 };

    /// the period for this easing curve
    double m_dPeriod { 0.3 };
};

} // namespace imanim
