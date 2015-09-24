/*
 * GreenPattern.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "../Patterns/GreenPattern.h"

GreenPattern::GreenPattern()
{
    // TODO Auto-generated constructor stub
}

GreenPattern::~GreenPattern()
{
    // TODO Auto-generated destructor stub
}

void GreenPattern::update(unsigned int deltaT)
{
    // This static pattern has no changes over time
}

void GreenPattern::draw(CRGB *frameBuffer)
{
    fill_gradient_RGB(frameBuffer, NUM_LEDS, CRGB(16, 16, 0), CRGB(0, 16, 0));
}
