/*
 * GreenPattern.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "../Patterns/GreenPattern.h"

GreenPattern::GreenPattern() {
	// TODO Auto-generated constructor stub

}

GreenPattern::~GreenPattern() {
	// TODO Auto-generated destructor stub
}

void GreenPattern::draw(CRGB *frameBuffer) {
	fill_solid(frameBuffer, NUM_LEDS, CRGB(0, 16, 0));
}
