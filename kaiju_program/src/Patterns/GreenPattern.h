/*
 * GreenPattern.h
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#ifndef PATTERN_GREENPATTERN_H_
#define PATTERN_GREENPATTERN_H_

#include "../Patterns/Pattern.h"

class GreenPattern: public Pattern {
public:
	GreenPattern();
	virtual ~GreenPattern();

	virtual void update(unsigned int deltaT);
	virtual void draw(CRGB *frameBuffer);
};

#endif /* PATTERN_GREENPATTERN_H_ */
