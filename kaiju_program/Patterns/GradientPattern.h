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
    GradientPattern(const TProgmemRGBPalette16 &palette, int colorStopDensity, int gradientStepTime);
    virtual ~GradientPattern();

    virtual void update(unsigned int deltaT);
    virtual void draw(CRGB *frameBuffer);
    virtual void reset();

protected:
    static CRGBPalette16 _currentPalette;

private:
    unsigned int _phase;

    const TProgmemRGBPalette16 &_paletteToCopy;
    int _gradientStepTime;
    int _colorStopDensity;
};

#endif /* GRADIENTPATTERN_H_ */
