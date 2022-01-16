/*
Disclaimer for Robert Penner's Easing Equations license:
TERMS OF USE - EASING EQUATIONS
Open source under the BSD License.
Copyright © 2001 Robert Penner
All rights reserved.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of the author nor the names of contributors may be used
      to endorse or promote products derived from this software without specific
      prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define _USE_MATH_DEFINES

#include "Easing.h"
#include <algorithm>
#include <cmath>

double imanim::Easing::easeNone(double t) 
{
    return t;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInQuad(double t)
{
    return t * t;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutQuad(double t)
{
    return -t * (t - 2.0);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutQuad(double t)
{
    t *= 2.0;
    if (t < 1.0)
    {
        return t * t / 2.0;
    }
    else
    {
        --t;
        return -0.5 * (t * (t - 2.0) - 1.0);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInQuad(double t)
{
    if (t < 0.5)
        return easeOutQuad(t * 2.0) / 2.0;
    else
        return easeInQuad((2.0 * t) - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInCubic(double t)
{
    return t * t * t;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutCubic(double t)
{
    t -= 1.0;
    return t * t * t + 1.0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutCubic(double t)
{
    t *= 2.0;
    if (t < 1.0)
    {
        return 0.5 * t * t * t;
    }
    else
    {
        t -= 2.0;
        return 0.5 * (t * t * t + 2.0);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInCubic(double t)
{
    if (t < 0.5)
        return easeOutCubic(2.0 * t) / 2.0;
    else
        return easeInCubic(2.0 * t - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInQuart(double t)
{
    return t * t * t * t;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutQuart(double t)
{
    t -= 1.0;
    return -(t * t * t * t - 1.0);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutQuart(double t)
{
    t *= 2.0;
    if (t < 1.0)
    {
        return 0.5 * t * t * t * t;
    }
    else
    {
        t -= 2.0;
        return -0.5 * (t * t * t * t - 2.0);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInQuart(double t)
{
    if (t < 0.5)
        return easeOutQuart(2.0 * t) / 2.0;
    else
        return easeInQuart(2.0 * t - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInQuint(double t)
{
    return t * t * t * t * t;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutQuint(double t)
{
    t -= 1.0;
    return t * t * t * t * t + 1.0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutQuint(double t)
{
    t *= 2.0;
    if (t < 1.0)
    {
        return 0.5 * t * t * t * t * t;
    }
    else
    {
        t -= 2.0;
        return 0.5 * (t * t * t * t * t + 2.0);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInQuint(double t)
{
    if (t < 0.5)
        return easeOutQuint(2.0 * t) / 2.0;
    else
        return easeInQuint(2.0 * t - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInSine(double t)
{
    return (t == 1.0) ? 1.0 : -cos(t * M_PI_2) + 1.0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutSine(double t)
{
    return sin(t * M_PI_2);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutSine(double t)
{
    return -0.5 * (cos(M_PI * t) - 1.0);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInSine(double t)
{
    if (t < 0.5)
        return easeOutSine(2.0 * t) / 2.0;
    else
        return easeInSine(2.0 * t - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInExpo(double t)
{
    return (t == 0.0 || t == 1.0) ? t : pow(2.0, 10.0 * (t - 1.0)) - 0.001;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutExpo(double t)
{
    return (t == 1.0) ? 1.0 : 1.001 * (-pow(2.0, -10 * t) + 1.0);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutExpo(double t)
{
    if (t == 0.0)
        return 0.0;
    if (t == 1.0)
        return 1.0;

    t *= 2.0;
    if (t < 1.0)
        return 0.5 * pow(2.0, 10.0 * (t - 1.0)) - 0.0005;
    else
        return 0.5 * 1.0005 * (-pow(2.0, -10.0 * (t - 1.0)) + 2.0);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInExpo(double t)
{
    if (t < 0.5)
        return easeOutExpo(2.0 * t) / 2.0;
    else
        return easeInExpo(2.0 * t - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInCirc(double t)
{
    return -(sqrt(1.0 - t * t) - 1.0);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutCirc(double t)
{
    t -= 1.0;
    return sqrt(1.0 - t * t);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutCirc(double t)
{
    t *= 2.0;
    if (t < 1.0)
    {
        return -0.5 * (sqrt(1.0 - t * t) - 1.0);
    }
    else
    {
        t -= 2.0;
        return 0.5 * (sqrt(1.0 - t * t) + 1.0);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInCirc(double t)
{
    if (t < 0.5)
        return easeOutCirc(2.0 * t) / 2.0;
    else
        return easeInCirc(2.0 * t - 1.0) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInElastic(double t, double a, double p)
{
    return easeInElasticHelper(t, 0.0, 1.0, 1.0, a, p);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutElastic(double t, double a, double p)
{
    return easeOutElasticHelper(t, 0.0, 1.0, 1.0, a, p);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutElastic(double t, double a, double p)
{
    if (t == 0.0)
        return 0.0;
    t *= 2.0;
    if (t == 2.0)
        return 1.0;

    double s;
    if (a < 1.0)
    {
        a = 1.0;
        s = p / 4.0;
    }
    else
    {
        s = p / (2.0 * M_PI) * asin(1.0 / a);
    }

    if (t < 1.0)
    {
        return -0.5 * (a * pow(2.0, 10.0 * (t - 1.0)) * sin((t - 1.0 - s) *
            (2.0 * M_PI) / p));
    }
    else
    {
        return a * pow(2.0, -10.0 * (t - 1.0)) * sin((t - 1.0 - s) *
            (2.0 * M_PI) / p) * 0.5 + 1.0;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInElastic(double t, double a, double p)
{
    if (t < 0.5)
        return easeOutElasticHelper(t * 2.0, 0.0, 0.5, 1.0, a, p);
    else
        return easeInElasticHelper(2.0 * t - 1.0, 0.5, 0.5, 1.0, a, p);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInBack(double t, double s)
{
    return t * t * ((s + 1.0) * t - s);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutBack(double t, double s)
{
    t -= 1.0;
    return t * t * ((s + 1.0) * t + s) + 1.0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutBack(double t, double s)
{
    t *= 2.0;
    if (t < 1.0)
    {
        s *= 1.525;
        return 0.5 * (t * t * ((s + 1.0) * t - s));
    }
    else
    {
        t -= 2.0;
        s *= 1.525;
        return 0.5 * (t * t * ((s + 1.0) * t + s) + 2.0);
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInBack(double t, double s)
{
    if (t < 0.5)
        return easeOutBack(2.0 * t, s) / 2.0;
    else
        return easeInBack(2.0 * t - 1.0, s) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInBounce(double t, double a)
{
    return 1.0 - easeOutBounceHelper(1.0 - t, 1.0, a);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutBounce(double t, double a)
{
    return easeOutBounceHelper(t, 1.0, a);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeInOutBounce(double t, double a)
{
    if (t < 0.5)
        return easeInBounce(2.0 * t, a) / 2.0;
    else
        return (t == 1.0) ? 1.0 : easeOutBounce(2.0 * t - 1.0, a) / 2.0 + 0.5;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutInBounce(double t, double a)
{
    if (t < 0.5)
        return easeOutBounceHelper(t * 2.0, 0.5, a);
    else
        return 1.0 - easeOutBounceHelper(2.0 - 2.0 * t, 0.5, a);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// private methods

double imanim::Easing::easeInElasticHelper(double t, double b, double c,
    double d, double a, double p)
{
    if (t == 0.0)
        return b;
    double t_adj = t / d;
    if (t_adj == 1.0)
        return b + c;

    double s;
    if (a < fabs(c))
    {
        a = c;
        s = p / 4.0;
    }
    else
    {
        s = p / (2.0 * M_PI) * asin(c / a);
    }

    t_adj -= 1.0;
    return -(a * pow(2.0, 10.0 * t_adj) * sin((t_adj * d - s) *
        (2.0 * M_PI) / p)) + b;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutBounceHelper(double t, double c, double a)
{
    if (t == 1.0)
        return c;
    if (t < (4.0 / 11.0))
    {
        return c * (7.5625 * t * t);
    }
    else if (t < (8.0 / 11.0))
    {
        t -= (6.0 / 11.0);
        return -a * (1.0 - (7.5625 * t * t + 0.75)) + c;
    }
    else if (t < (10.0 / 11.0))
    {
        t -= (9.0 / 11.0);
        return -a * (1.0 - (7.5625 * t * t + 0.9375)) + c;
    }
    else
    {
        t -= (21.0 / 22.0);
        return -a * (1.0 - (7.5625 * t * t + 0.984375)) + c;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

double imanim::Easing::easeOutElasticHelper(double t, double /*b*/,
    double c, double /*d*/, double a, double p)
{
    if (t == 0.0)
        return 0.0;
    if (t == 1.0)
        return c;

    double s;
    if (a < c)
    {
        a = c;
        s = p / 4.0;
    }
    else
    {
        s = p / (2.0 * M_PI) * asin(c / a);
    }

    return (a * pow(2.0, -10.0 * t) * sin((t - s) * (2.0 * M_PI) / p) + c);
}
