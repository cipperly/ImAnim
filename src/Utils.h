#pragma once

#include <cfloat>

namespace imanim
{

/**
 * @brief Provides utility methods
 */
class Utils
{
public:

    /**
     * Returns whether the two values are nearly equal to each other within the
     * specified tolerance
     * @param dValue1 the first value of the comparison
     * @param dValue2 the second value of the comparison
     * @param dTolerance the tolerance that the two values must be within
     * @return true if the values are nearly equal; false otherwise
     */
    [[nodiscard]] static bool nearlyEqual(double dValue1, double dValue2,
        double dTolerance = DBL_EPSILON);
};

} // namespace imanim
