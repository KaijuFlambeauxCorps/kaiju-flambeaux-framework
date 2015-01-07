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

	virtual CRGB GetColor() { return CRGB(0, 0, 64); }
};

#endif /* PATTERN_BLUEPATTERN_H_ */
