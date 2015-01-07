/*
 * BluePattern.h
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#ifndef PATTERN_BLUEPATTERN_H_
#define PATTERN_BLUEPATTERN_H_

#include "../Patterns/Pattern.h"

class BluePattern: public Pattern {
public:
	BluePattern();
	virtual ~BluePattern();

	virtual void update(unsigned int deltaT);
	virtual void draw(CRGB *frameBuffer);
};

#endif /* PATTERN_BLUEPATTERN_H_ */
