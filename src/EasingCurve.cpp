#include "EasingCurve.h"
#include "Easing.h"
#include <algorithm>

imanim::EasingCurve::EasingCurve(EasingCurve::Type eType)
    : m_eType(eType)
{
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::EasingCurve::calculateValueForProgress(double dProgress)
{
    double dValue = dProgress;
    dProgress = std::clamp(dProgress, 0.0, 1.0);

    switch (m_eType)
    {
    case Type::Linear:
        dValue = imanim::Easing::easeNone(dProgress);
        break;
    case Type::InQuad:
        dValue = imanim::Easing::easeInQuad(dProgress);
        break;
    case Type::OutQuad:
        dValue = imanim::Easing::easeOutQuad(dProgress);
        break;
    case Type::InOutQuad:
        dValue = imanim::Easing::easeInOutQuad(dProgress);
        break;
    case Type::OutInQuad:
        dValue = imanim::Easing::easeOutInQuad(dProgress);
        break;
    case Type::InCubic:
        dValue = imanim::Easing::easeInCubic(dProgress);
        break;
    case Type::OutCubic:
        dValue = imanim::Easing::easeOutCubic(dProgress);
        break;
    case Type::InOutCubic:
        dValue = imanim::Easing::easeInOutCubic(dProgress);
        break;
    case Type::OutInCubic:
        dValue = imanim::Easing::easeOutInCubic(dProgress);
        break;
    case Type::InQuart:
        dValue = imanim::Easing::easeInQuart(dProgress);
        break;
    case Type::OutQuart:
        dValue = imanim::Easing::easeOutQuart(dProgress);
        break;
    case Type::InOutQuart:
        dValue = imanim::Easing::easeInOutQuart(dProgress);
        break;
    case Type::OutInQuart:
        dValue = imanim::Easing::easeOutInQuart(dProgress);
        break;
    case Type::InQuint:
        dValue = imanim::Easing::easeInQuint(dProgress);
        break;
    case Type::OutQuint:
        dValue = imanim::Easing::easeOutQuint(dProgress);
        break;
    case Type::InOutQuint:
        dValue = imanim::Easing::easeInOutQuint(dProgress);
        break;
    case Type::OutInQuint:
        dValue = imanim::Easing::easeOutInQuint(dProgress);
        break;
    case Type::InSine:
        dValue = imanim::Easing::easeInSine(dProgress);
        break;
    case Type::OutSine:
        dValue = imanim::Easing::easeOutSine(dProgress);
        break;
    case Type::InOutSine:
        dValue = imanim::Easing::easeInOutSine(dProgress);
        break;
    case Type::OutInSine:
        dValue = imanim::Easing::easeOutInSine(dProgress);
        break;
    case Type::InExpo:
        dValue = imanim::Easing::easeInExpo(dProgress);
        break;
    case Type::OutExpo:
        dValue = imanim::Easing::easeOutExpo(dProgress);
        break;
    case Type::InOutExpo:
        dValue = imanim::Easing::easeInOutExpo(dProgress);
        break;
    case Type::OutInExpo:
        dValue = imanim::Easing::easeOutInExpo(dProgress);
        break;
    case Type::InCirc:
        dValue = imanim::Easing::easeInCirc(dProgress);
        break;
    case Type::OutCirc:
        dValue = imanim::Easing::easeOutCirc(dProgress);
        break;
    case Type::InOutCirc:
        dValue = imanim::Easing::easeInOutCirc(dProgress);
        break;
    case Type::OutInCirc:
        dValue = imanim::Easing::easeOutInCirc(dProgress);
        break;
    case Type::InElastic:
        dValue = imanim::Easing::easeInElastic(dProgress, m_dAmplitude,
            m_dPeriod);
        break;
    case Type::OutElastic:
        dValue = imanim::Easing::easeOutElastic(dProgress, m_dAmplitude,
            m_dPeriod);
        break;
    case Type::InOutElastic:
        dValue = imanim::Easing::easeInOutElastic(dProgress, m_dAmplitude,
            m_dPeriod);
        break;
    case Type::OutInElastic:
        dValue = imanim::Easing::easeOutInElastic(dProgress, m_dAmplitude,
            m_dPeriod);
        break;
    case Type::InBack:
        dValue = imanim::Easing::easeInBack(dProgress, m_dOvershoot);
        break;
    case Type::OutBack:
        dValue = imanim::Easing::easeOutBack(dProgress, m_dOvershoot);
        break;
    case Type::InOutBack:
        dValue = imanim::Easing::easeInOutBack(dProgress, m_dOvershoot);
        break;
    case Type::OutInBack:
        dValue = imanim::Easing::easeOutInBack(dProgress, m_dOvershoot);
        break;
    case Type::InBounce:
        dValue = imanim::Easing::easeInBounce(dProgress, m_dAmplitude);
        break;
    case Type::OutBounce:
        dValue = imanim::Easing::easeOutBounce(dProgress, m_dAmplitude);
        break;
    case Type::InOutBounce:
        dValue = imanim::Easing::easeInOutBounce(dProgress, m_dAmplitude);
        break;
    case Type::OutInBounce:
        dValue = imanim::Easing::easeOutInBounce(dProgress, m_dAmplitude);
        break;
    }

    return dValue;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::EasingCurve::getAmplitude() const
{
    return m_dAmplitude;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::EasingCurve::getOvershoot() const
{
    return m_dOvershoot;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::EasingCurve::getPeriod() const
{
    return m_dPeriod;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

imanim::EasingCurve::Type imanim::EasingCurve::getType() const
{
    return m_eType;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::EasingCurve::setAmplitude(double dAmplitude)
{
    if (dAmplitude >= 0.0)
    {
        m_dAmplitude = dAmplitude;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::EasingCurve::setOvershoot(double dOvershoot)
{
    if (dOvershoot >= 0.0)
    {
        m_dOvershoot = dOvershoot;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::EasingCurve::setPeriod(double dPeriod)
{
    if (dPeriod >= 0.0)
    {
        m_dPeriod = dPeriod;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::EasingCurve::setType(imanim::EasingCurve::Type eType)
{
    m_eType = eType;
}
