/*
 * PatternCycler.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "PatternCycler.h"

PatternCycler::PatternCycler()
: _patterns { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  _currentPatternIndex(0),
  _patternCount(0)
{
	// TODO Auto-generated constructor stub

}

PatternCycler::~PatternCycler() {
	// TODO Auto-generated destructor stub
}

void PatternCycler::addPattern(Pattern *pattern) {
	_patterns[_patternCount] = pattern;
	_patternCount++;
}

void PatternCycler::cycleToNext() {
	// Increment and wrap around
	_currentPatternIndex++;
	_currentPatternIndex %= _patternCount;
}

Pattern *PatternCycler::currentPattern() {
	return _patterns[_currentPatternIndex];
}
