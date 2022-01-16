#pragma once

namespace imanim
{

/**
 * @brief Provides easing equations
 */
class Easing
{
public:

    /**
     * @brief Easing equation for a simple linear tweening, with no easing
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeNone(double t);

    /**
     * @brief Easing equation for a quadratic (t^2) easing in, accelerating from
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInQuad(double t);

    /**
     * @brief Easing equation for a quadratic (t^2) easing out, decelerating to
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutQuad(double t);

    /**
     * @brief Easing equation for a quadratic (t^2) easing in/out, accelerating
     * until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutQuad(double t);

    /**
     * @brief Easing equation for a quadratic (t^2) easing out/in, decelerating
     * until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInQuad(double t);

    /**
     * @brief Easing equation for a cubic (t^3) easing in, accelerating from
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInCubic(double t);

    /**
     * @brief Easing equation for a cubic (t^3) easing out, decelerating to
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutCubic(double t);

    /**
     * @brief Easing equation for a cubic (t^3) easing in/out, accelerating
     * until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutCubic(double t);

    /**
     * @brief Easing equation for a cubic (t^3) easing out/in, decelerating
     * until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInCubic(double t);

    /**
     * @brief Easing equation for a quartic (t^4) easing in, accelerating from
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInQuart(double t);

    /**
     * @brief Easing equation for a quartic (t^4) easing out, decelerating to
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutQuart(double t);

    /**
     * @brief Easing equation for a quartic (t^4) easing in/out, accelerating
     * until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutQuart(double t);

    /**
     * @brief Easing equation for a quartic (t^4) easing out/in, decelerating
     * until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInQuart(double t);

    /**
     * @brief Easing equation for a quintic (t^5) easing in, accelerating from
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInQuint(double t);

    /**
     * @brief Easing equation for a quintic (t^5) easing out, decelerating to
     * zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutQuint(double t);

    /**
     * @brief Easing equation for a quintic (t^5) easing in/out, accelerating
     * until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutQuint(double t);

    /**
     * @brief Easing equation for a quintic (t^5) easing out/in, decelerating
     * until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInQuint(double t);

    /**
     * @brief Easing equation for a sinusoidal (sin(t)) easing in, accelerating
     * from zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInSine(double t);

    /**
     * @brief Easing equation for a sinusoidal (sin(t)) easing out, decelerating
     * to zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutSine(double t);

    /**
     * @brief Easing equation for a sinusoidal (sin(t)) easing in/out,
     * accelerating until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutSine(double t);

    /**
     * @brief Easing equation for a sinusoidal (sin(t)) easing out/in,
     * decelerating until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInSine(double t);

    /**
     * @brief Easing equation for an exponential (2^t) easing in, accelerating
     * from zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInExpo(double t);

    /**
     * @brief Easing equation for an exponential (2^t) easing out, decelerating
     * to zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutExpo(double t);

    /**
     * @brief Easing equation for an exponential (2^t) easing in/out,
     * accelerating until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutExpo(double t);

    /**
     * @brief Easing equation for an exponential (2^t) easing out/in,
     * decelerating until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInExpo(double t);

    /**
     * @brief Easing equation for a circular (sqrt(1-t^2)) easing in,
     * accelerating from zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInCirc(double t);

    /**
     * @brief Easing equation for a circular (sqrt(1-t^2)) easing out,
     * decelerating to zero velocity
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutCirc(double t);

    /**
     * @brief Easing equation for a circular (sqrt(1-t^2)) easing in/out,
     * accelerating until halfway, then decelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeInOutCirc(double t);

    /**
     * @brief Easing equation for a circular (sqrt(1-t^2)) easing out/in,
     * decelerating until halfway, then accelerating
     * @param t current time in frames or seconds
     * @return the calculated time
     */
    static double easeOutInCirc(double t);

    /**
     * @brief Easing equation for an elastic (exponentially decaying sine wave)
     * easing in, accelerating from zero velocity
     * @param t current time in frames or seconds
     * @param a the amplitude of the elastic "spring" effect
     * @param p the period, where a small value will give a high frequency of
     *      the curve and a large period will give it a small frequency
     * @return the calculated time
     */
    static double easeInElastic(double t, double a, double p);

    /**
     * @brief Easing equation for an elastic (exponentially decaying sine wave)
     * easing out, decelerating to zero velocity
     * @param t current time in frames or seconds
     * @param a the amplitude of the elastic "spring" effect
     * @param p the period, where a small value will give a high frequency of
     *      the curve and a large period will give it a small frequency
     * @return the calculated time
     */
    static double easeOutElastic(double t, double a, double p);

    /**
     * @brief Easing equation for an elastic (exponentially decaying sine wave)
     * easing in/out, accelerating until halfway, then decelerating
     * @param t current time in frames or seconds
     * @param a the amplitude of the elastic "spring" effect
     * @param p the period, where a small value will give a high frequency of
     *      the curve and a large period will give it a small frequency
     * @return the calculated time
     */
    static double easeInOutElastic(double t, double a, double p);

    /**
     * @brief Easing equation for an elastic (exponentially decaying sine wave)
     * easing out/in, decelerating until halfway, then accelerating
     * @param t current time in frames or seconds
     * @param a the amplitude of the elastic "spring" effect
     * @param p the period, where a small value will give a high frequency of
     *      the curve and a large period will give it a small frequency
     * @return the calculated time
     */
    static double easeOutInElastic(double t, double a, double p);

    /**
     * @brief Easing equation for a back (overshooting cubic easing:
     * (s+1)*t^3 - s*t^2) easing in, accelerating from zero velocity
     * @param t current time in frames or seconds
     * @param s overshoot amount where higher means greater overshoot (0
     *      produces cubic easing with no overshoot, and the default value of
     *      1.70158 produces an overshoot of 10 percent)
     * @return the calculated time
     */
    static double easeInBack(double t, double s);

    /**
     * @brief Easing equation for a back (overshooting cubic easing:
     * (s+1)*t^3 - s*t^2) easing out, decelerating to zero velocity
     * @param t current time in frames or seconds
     * @param s overshoot amount where higher means greater overshoot (0
     *      produces cubic easing with no overshoot, and the default value of
     *      1.70158 produces an overshoot of 10 percent)
     * @return the calculated time
     */
    static double easeOutBack(double t, double s);

    /**
     * @brief Easing equation for a back (overshooting cubic easing:
     * (s+1)*t^3 - s*t^2)  easing in/out, accelerating until halfway, then
     * decelerating
     * @param t current time in frames or seconds
     * @param s overshoot amount where higher means greater overshoot (0
     *      produces cubic easing with no overshoot, and the default value of
     *      1.70158 produces an overshoot of 10 percent)
     * @return the calculated time
     */
    static double easeInOutBack(double t, double s);

    /**
     * @brief Easing equation for a back (overshooting cubic easing:
     * (s+1)*t^3 - s*t^2) easing out/in, decelerating until halfway, then
     * accelerating
     * @param t current time in frames or seconds
     * @param s overshoot amount where higher means greater overshoot (0
     *      produces cubic easing with no overshoot, and the default value of
     *      1.70158 produces an overshoot of 10 percent)
     * @return the calculated time
     */
    static double easeOutInBack(double t, double s);

    /**
     * @brief Easing equation for a bounce (exponentially decaying parabolic
     * bounce) easing in, accelerating from zero velocity
     * @param t current time in frames or seconds
     * @param a the amplitude of the bounce effect
     * @return the calculated time
     */
    static double easeInBounce(double t, double a);

    /**
     * @brief Easing equation for a bounce (exponentially decaying parabolic
     * bounce) easing out, decelerating to zero velocity
     * @param t current time in frames or seconds
     * @param a the amplitude of the bounce effect
     * @return the calculated time
     */
    static double easeOutBounce(double t, double a);

    /**
     * @brief Easing equation for a bounce (exponentially decaying parabolic
     * bounce)  easing in/out, accelerating until halfway, then decelerating
     * @param t current time in frames or seconds
     * @param a the amplitude of the bounce effect
     * @return the calculated time
     */
    static double easeInOutBounce(double t, double a);

    /**
     * @brief Easing equation for a bounce (exponentially decaying parabolic
     * bounce) easing out/in, decelerating until halfway, then accelerating
     * @param t current time in frames or seconds
     * @param a the amplitude of the bounce effect
     * @return the calculated time
     */
    static double easeOutInBounce(double t, double a);

private:

    /**
     * @brief Helper for calculating easing equation for an elastic easing in
     */
    static double easeInElasticHelper(double t, double b, double c, double d,
        double a, double p);

    /**
     * @brief Helper for calculating easing equation for a bounce easing out
     */
    static double easeOutBounceHelper(double t, double c, double a);

    /**
     * @brief Helper for calculating easing equation for an elastic easing out
     */
    static double easeOutElasticHelper(double t, double b, double c, double d,
        double a, double p);
};

} // namespace imanim
