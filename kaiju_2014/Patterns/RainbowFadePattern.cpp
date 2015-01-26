/*
 * RainbowFadePattern.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "RainbowFadePattern.h"

RainbowFadePattern::RainbowFadePattern()
        : _time(0)
{
    // TODO Auto-generated constructor stub
}

RainbowFadePattern::~RainbowFadePattern()
{
    // TODO Auto-generated destructor stub
}

void RainbowFadePattern::update(unsigned int deltaT)
{
    _time += deltaT;
}

void RainbowFadePattern::draw(CRGB *frameBuffer)
{
    fill_rainbow(frameBuffer, NUM_LEDS, (_time / 10) & 0xFF, 6);

    // Dim the brightness a little (or a lot)
    for (unsigned char pixel = 0; pixel < NUM_LEDS; ++pixel) {
        frameBuffer[pixel].nscale8(96);
    }
}
