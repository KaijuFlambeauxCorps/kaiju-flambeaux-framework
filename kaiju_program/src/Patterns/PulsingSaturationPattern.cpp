/*
 * PulsingSaturationPattern.cpp
 *
 *  Created on: 20 Jan 2015
 *      Author: tully
 */

#include "PulsingSaturationPattern.h"
#include "lib8tion.h"

PulsingSaturationPattern::PulsingSaturationPattern(unsigned char hue, unsigned char val, unsigned int period)
: _hue(hue),
  _val(val),
  _period(period),
  _phase(0)
{
}

PulsingSaturationPattern::~PulsingSaturationPattern()
{
}


void PulsingSaturationPattern::reset()
{
    _phase = 0;
}

void PulsingSaturationPattern::update(unsigned int deltaT)
{
    _phase += deltaT;
    _phase %= _period;
}

void PulsingSaturationPattern::draw(CRGB *frameBuffer)
{
    // Determine the saturation
    int sineWave = sin16((unsigned int)((_phase * (unsigned long)65536) / _period));
    sineWave = (sineWave >> 8) + 128;

    CRGB rgb;
    hsv2rgb_rainbow(CHSV(_hue, (unsigned char)sineWave, _val), rgb);
    fill_solid(frameBuffer, NUM_LEDS, rgb);
}
