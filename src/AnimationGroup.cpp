#include "AnimationGroup.h"
#include <algorithm>

void imanim::AnimationGroup::addAnimation(AbstractAnimation *pAnimation)
{
    if (pAnimation != nullptr)
    {
        m_vecAnimations.push_back(pAnimation);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AnimationGroup::clear()
{
    m_vecAnimations.clear();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

imanim::AbstractAnimation *imanim::AnimationGroup::getAnimationAt(int nIndex)
    const
{
    AbstractAnimation *pAnimation = nullptr;

    if ((nIndex >= 0) && (nIndex < m_vecAnimations.size()))
    {
        pAnimation = m_vecAnimations[nIndex];
    }

    return pAnimation;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int imanim::AnimationGroup::getAnimationCount() const
{
    return static_cast<int>(m_vecAnimations.size());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void imanim::AnimationGroup::insertAnimation(int nIndex,
    AbstractAnimation *pAnimation)
{
    if (pAnimation == nullptr)
    {
        return;
    }

    if (nIndex < 0)
    {
        nIndex = 0;
    }

    if (nIndex >= m_vecAnimations.size())
    {
        m_vecAnimations.push_back(pAnimation);
    }
    else
    {
        m_vecAnimations.insert(m_vecAnimations.begin() + nIndex, pAnimation);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int imanim::AnimationGroup::removeAnimation(AbstractAnimation *pAnimation)
{
    int nRemoveCount = 0;

    for (auto iter = m_vecAnimations.begin(); iter != m_vecAnimations.end();)
    {
        if (*iter == pAnimation)
        {
            iter = m_vecAnimations.erase(iter);
            nRemoveCount++;
        }
        else
        {
            ++iter;
        }
    }

    return nRemoveCount;
}
