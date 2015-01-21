/*
 * PulsingSaturationPattern.h
 *
 *  Created on: 20 Jan 2015
 *      Author: tully
 */

#ifndef PULSINGSATURATIONPATTERN_H_
#define PULSINGSATURATIONPATTERN_H_

#include "Pattern.h"

class PulsingSaturationPattern: public Pattern
{
public:
    PulsingSaturationPattern(unsigned char hue, unsigned char val, unsigned int period);
    virtual ~PulsingSaturationPattern();

    virtual void update(unsigned int deltaT);
    virtual void draw(CRGB *frameBuffer);

private:
    const unsigned char _hue;
    const unsigned char _val;
    const unsigned int _period;

    unsigned int _phase;
};

#endif /* PULSINGSATURATIONPATTERN_H_ */
