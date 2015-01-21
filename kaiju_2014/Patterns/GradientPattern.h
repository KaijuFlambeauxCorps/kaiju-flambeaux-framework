/*
 * GradientPattern.h
 *
 *  Created on: 21 Jan 2015
 *      Author: tully
 */

#ifndef GRADIENTPATTERN_H_
#define GRADIENTPATTERN_H_

#define GRADIENT_INDICES 256

#include "Pattern.h"

class GradientPattern: public Pattern
{
public:
    GradientPattern(const TProgmemRGBPalette16 &palette);
    virtual ~GradientPattern();

    virtual void update(unsigned int deltaT);
    virtual void draw(CRGB *frameBuffer);
    virtual void reset();

protected:
    static CRGBPalette16 _currentPalette;

private:
    unsigned int _phase;

    const TProgmemRGBPalette16 &_paletteToCopy;
    static const int _gradientStepTime = 30;
    static const int _colorStopDensity = 16;
};

#endif /* GRADIENTPATTERN_H_ */
