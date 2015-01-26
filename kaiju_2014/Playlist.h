/*
 * Playlist.h
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Patterns/Pattern.h"

class Playlist
{
public:
    Playlist();
    virtual ~Playlist();

    // Adds a pattern to the collection
    void addPattern(Pattern *pattern);
    void cycleToNext();
    void goToPattern(unsigned char patternIndex);

    Pattern* currentPattern();

    unsigned char getCurrentPatternIndex() const
    {
        return _currentPatternIndex;
    }

private:
    Pattern *_patterns[12];
    unsigned char _currentPatternIndex;
    unsigned char _patternCount;
};

#endif /* PLAYLIST_H_ */
