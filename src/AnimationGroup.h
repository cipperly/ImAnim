#pragma once

#include "AbstractAnimation.h"
#include <vector>

namespace imanim
{

/**
 * @brief The base for a group of animations
 */
class AnimationGroup : public AbstractAnimation
{
public:

    /**
     * Adds the specified animation to this group
     * @param pAnimation the animation to add
     */
    void addAnimation(AbstractAnimation *pAnimation);

    /**
     * Clears the list of animations, removing all animations from this group
     */
    void clear();

    /**
     * Returns the animation at the specified index into this group of
     * animations
     * @param nIndex the index into this group of animations; must be in the
     *      range of 0 to (getAnimationCount() - 1)
     * @return the animation at the index; nullptr if an invalid index
     */
    [[nodiscard]] AbstractAnimation *getAnimationAt(int nIndex) const;

    /**
     * Returns the number of animations in this group
     * @return this group's animation count
     */
    [[nodiscard]] int getAnimationCount() const;

    /**
     * Returns the vector of animations in this group
     * @return the animations in this group
     */
    [[nodiscard]] const std::vector<AbstractAnimation *> &getAnimations() const
    { return m_vecAnimations; }

    /**
     * Inserts the animation into the specified index in this animation group
     * @param nIndex the index to insert the animation; if <= 0, inserts at the
     *      beginning; if >= getAnimationCount(), inserts at the end
     * @param pAnimation the animation to insert into this group
     */
    void insertAnimation(int nIndex, AbstractAnimation *pAnimation);

    /**
     * Removes all instances of the specified animation from this group
     * @param pAnimation the animation to remove
     * @return the number of instances removed; 0 if not found
     */
    int removeAnimation(AbstractAnimation *pAnimation);

protected:

    /// the list of animations in this group
    std::vector<AbstractAnimation *> m_vecAnimations;
};

} // namespace imanim
