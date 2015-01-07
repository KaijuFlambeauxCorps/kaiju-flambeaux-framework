/*
 * Pattern.h
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#ifndef PATTERN_PATTERN_H_
#define PATTERN_PATTERN_H_

#include "pixeltypes.h"

class Pattern {
public:
	Pattern();
	virtual ~Pattern();

	virtual CRGB GetColor() = 0;
};

#endif /* PATTERN_PATTERN_H_ */
