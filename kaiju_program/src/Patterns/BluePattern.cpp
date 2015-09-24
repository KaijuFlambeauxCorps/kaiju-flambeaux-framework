/*
 * BluePattern.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "../Patterns/BluePattern.h"

BluePattern::BluePattern()
{
    // TODO Auto-generated constructor stub
}

BluePattern::~BluePattern()
{
    // TODO Auto-generated destructor stub
}

void BluePattern::update(unsigned int deltaT)
{
    // This static pattern has no changes over time
}

void BluePattern::draw(CRGB *frameBuffer)
{
    fill_gradient_RGB(frameBuffer, NUM_LEDS, CRGB(0, 0, 16), CRGB(16, 16, 16));
}

