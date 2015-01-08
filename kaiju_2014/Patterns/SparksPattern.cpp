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

#include "../Patterns/SparksPattern.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hsv2rgb.h"

SparksPattern::SparksPattern(CRGB *rgbBuffer,
	unsigned char length,
	unsigned char sparkleTrailLength,
	unsigned char valFalloffDistance,
    unsigned char valMin,
    unsigned char valMax,
    unsigned char sparkDistance,
    unsigned char startOffset)
: _length(length),
_framesUntilNewSpark(startOffset),
_sparkDistance(sparkDistance),
_sparkleTrailLength(sparkleTrailLength),
_valFalloffDistance(valFalloffDistance),
_valMin(valMin),
_valMax(valMax),
_sparkCount(1)
{
	_buffer.rgb = rgbBuffer;

    _maxSparks = length / sparkDistance + 2;
    if (length % sparkDistance == 0) _maxSparks--;

    _sparks = new Spark[_maxSparks];
    _sparks[0] = Spark(0, length - 1);
}

void SparksPattern::update(unsigned int deltaT)
{
	// First, advance all sparks
	for (int i = 0; i < _sparkCount; i++)
        _sparks[i].position++;

	// Next, prune a spark if we are able.
    // We can only destroy a spark if:
    //   - There are at least two sparks
    //  && Spark before it has reached the end
    if (_sparkCount > 1)
    {
    	Spark &secondToLast = _sparks[_sparkCount - 2];

        if (secondToLast.position >= (_length - 1))
        {
        	_sparkCount--;
        }
    }

    if (--_framesUntilNewSpark == 0)
    {
        _framesUntilNewSpark = _sparkDistance;

        pushSparkToFront(pickHue());
    }
}

unsigned char SparksPattern::pickHue()
{
    return rand() % HUE_MAX_RAINBOW;
}

void SparksPattern::pushSparkToFront(unsigned char hue)
{
	for (int i = _maxSparks - 2; i >= 0; i--)
	{
		_sparks[i + 1] = _sparks[i];
	}

	_sparks[0].position = 0;
	_sparks[0].hue = hue;
	_sparkCount++;
}

inline int interpolate(int a, int b, int t, int range_t) {
    return ((a*t) / range_t)
           +
           (b*(range_t - t) / range_t);
}

unsigned char SparksPattern::pixelVal(unsigned char leadingSparkPosition, unsigned char pixelPosition)
{
	unsigned char distance = leadingSparkPosition - pixelPosition;
    if (distance > _valFalloffDistance)
        return _valMin;

    return interpolate(_valMin, _valMax, distance, _valFalloffDistance);
}


void SparksPattern::draw(CRGB *frameBuffer)
{
    int lastSparkHead = -1;

    // Iterate forward through the sparks
    for (int i = 0; i < _sparkCount; i++)
    {
    	Spark &spark = _sparks[i];
        // - Find the position of this spark
        int startIdx = spark.position;

        // - If the spark is beyond the end, we still need to draw its body and tail
        //   (we just can't render its head, or anything beyond the framebuffer)
        if (startIdx >= _length)
        {
            startIdx = _length - 1;
        }

        // - Iterate backwards until the head of the last spark
        for (int pixelIdx = startIdx; pixelIdx > lastSparkHead; pixelIdx--)
        {
            CHSV &pixel = _buffer.hsv[pixelIdx];

            //   - Set pixel hue to curent spark's hue
            pixel.hue = spark.hue;

            //   - Set pixel saturation:
            //     - (HEAD) 0
            //     - (BODY) random
            //     - (TAIL) 255
            if (pixelIdx == spark.position)
            {
                pixel.sat = 0;
            }
            else if (spark.position - pixelIdx <= _sparkleTrailLength)
            {
                // Saturation = 100% - RandomElement({ 0xff, 0x7f, 0x3f, 0x1f, 0x0f })
                //    leaving possible sat values of { 0x00, 0x70, 0xc0, 0xe0, 0xf0 }
                pixel.sat = 0xff - (0xff >> (rand() % 5));
                //pixel.sat = interpolate(255, 0, spark.Position - pixelIdx, _sparkleTrailLength);
            }
            else
            {
                pixel.sat = 255;
            }

            // Set pixel value based on the falloff function
            pixel.val = pixelVal(spark.position, pixelIdx);
        }

        lastSparkHead = spark.position;
    }

    hsv2rgb_rainbow(_buffer.hsv, _buffer.rgb, _length);
}

SparksPattern::~SparksPattern()
{
}

