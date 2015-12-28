/*
 * Copyright (c) 2014 Daniel Tullemans <tully@be-lumino.us>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef PATTERN_SPARKSPATTERN_H_
#define PATTERN_SPARKSPATTERN_H_

#define MAX_SPARKS 12

#include <stdlib.h>
#include "../Patterns/Pattern.h"

struct Spark;

union CombinedBuffer
{
    CHSV *hsv;
    CRGB *rgb;
};

typedef unsigned char (*HueSelector)();

class SparksPattern: public Pattern
{
public:
    SparksPattern(CRGB *rgbBuffer,
                  unsigned char length,
                  int framesPerSecond,
                  unsigned char sparkleTrailLength,
                  unsigned char valFalloffDistance,
                  unsigned char valMin,
                  unsigned char valMax,
                  unsigned char sparkDistance,
                  unsigned char startOffset = 1,
                  HueSelector hueSelector = NULL);
    virtual ~SparksPattern();

    virtual void update(unsigned int deltaT);
    virtual void draw(CRGB *frameBuffer);

protected:
    virtual unsigned char pickHue();

private:
    unsigned char _length;
    unsigned char _framesUntilNewSpark;

    int _timeUntilNextFrame;
    const int _timeBetweenFrames;

    const unsigned char _sparkDistance;
    const unsigned char _sparkleTrailLength;
    const unsigned char _valFalloffDistance;
    const unsigned char _valMin;
    const unsigned char _valMax;

    HueSelector _hueSelector;

    // This static allocation is a hack to save 24 bytes of memory, and I never should have written it. -- tully
    static Spark _sparks[MAX_SPARKS];
    static unsigned char _sparkCount;

    CombinedBuffer _buffer;

    unsigned char pixelVal(unsigned char leadingSparkPosition,
                           unsigned char pixelPosition);
    void pushSparkToFront(unsigned char hue);
    void advanceSparks();
};

struct Spark
{
    Spark()
            : hue(0),
              position(0)
    {
    }
    Spark(const Spark &rhs)
    {
        hue = rhs.hue;
        position = rhs.position;
    }
    Spark(unsigned char h, unsigned char position = 0)
            : hue(h),
              position(position)
    {
    }
    unsigned char hue;
    unsigned char position;
};

#endif // PATTERN_SPARKSPATTERN_H_
