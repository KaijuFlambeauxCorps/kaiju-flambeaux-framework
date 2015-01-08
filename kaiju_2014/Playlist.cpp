/*
 * PatternCycler.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "Playlist.h"

Playlist::Playlist()
        : _patterns { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
          _currentPatternIndex(0),
          _patternCount(0)
{
    // TODO Auto-generated constructor stub

}

Playlist::~Playlist()
{
    // TODO Auto-generated destructor stub
}

void Playlist::addPattern(Pattern *pattern)
{
    _patterns[_patternCount] = pattern;
    _patternCount++;
}

void Playlist::cycleToNext()
{
    // Increment and wrap around
    _currentPatternIndex++;
    _currentPatternIndex %= _patternCount;
}

Pattern *Playlist::currentPattern()
{
    return _patterns[_currentPatternIndex];
}
