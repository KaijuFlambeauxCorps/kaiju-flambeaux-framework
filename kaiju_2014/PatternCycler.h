/*
 * PatternCycler.h
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#ifndef PATTERNCYCLER_H_
#define PATTERNCYCLER_H_

#include "Patterns/Pattern.h"

class PatternCycler {
public:
	PatternCycler();
	virtual ~PatternCycler();

	// Adds a pattern to the collection
	void addPattern(Pattern *pattern);
	void cycleToNext();

	Pattern* currentPattern();

private:
	Pattern *_patterns[10];
	unsigned char _currentPatternIndex;
	unsigned char _patternCount;
};

#endif /* PATTERNCYCLER_H_ */
