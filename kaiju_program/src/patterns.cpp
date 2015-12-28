/*
 * patterns.cpp
 *
 *  Created on: 26 Jan 2015
 *      Author: tully
 */

#include "config.h"

#include "led_sysdefs.h"
#include "hsv2rgb.h"
#include "colorpalettes.h"

#include "Patterns/Pattern.h"
#include "Patterns/GradientPattern.h"
#include "Patterns/PulsingSaturationPattern.h"
#include "Patterns/BluePattern.h"
#include "Patterns/GreenPattern.h"
#include "Patterns/RainbowFadePattern.h"
#include "Patterns/SparksPattern.h"

#include "Playlist.h"

extern CRGB frameBuffer[];

extern const TProgmemRGBPalette16 MardiGrasColors_p PROGMEM =
{
    0x8800CC, 0xAA00FF, 0xFF00FF, 0x8800CC, 0x000000, // Purple
    0x003300, 0x00AA00, 0x00FF00, 0x003300, 0x000000, // Green
    0x669900, 0x99AA00, 0xCCAA00, 0x996600, 0x000000, // Gold
    0x000000
};

GradientPattern mardiGrasGradient(MardiGrasColors_p, 4, 33);
GradientPattern rainbowStripeGradient(RainbowStripeColors_p, 4, 33);
GradientPattern forestGradient(ForestColors_p, 4, 33);
GradientPattern lavaGradient(LavaColors_p, 4, 33);
PulsingSaturationPattern pulsePurple(190, 128, 1000);
PulsingSaturationPattern pulseGreen(90, 128, 700);
PulsingSaturationPattern pulseGold(50, 128, 450);
RainbowFadePattern rainbow;
SparksPattern sparks(frameBuffer, NUM_LEDS, 24, 3, 10, 96, 140, 20);


unsigned char mgSelector()
{
    switch(random8(6))
    {
        case 0:
        case 1:
            return 190; // purple
        case 2:
        case 3:
            return 50; // yellow
        case 4:
        case 5:
        default:
            return 90; // green
    }
}
SparksPattern mgSparks(frameBuffer, NUM_LEDS, 24, 3, 10, 96, 140, 20, 1, mgSelector);

extern Playlist playlist;

void addPatternsToPlaylist()
{
    playlist.addPattern(&mgSparks);
    playlist.addPattern(&rainbowStripeGradient);

    playlist.addPattern(&mardiGrasGradient);
    playlist.addPattern(&sparks);

    playlist.addPattern(&forestGradient);
    playlist.addPattern(&pulsePurple);

    playlist.addPattern(&lavaGradient);
    playlist.addPattern(&pulseGreen);

    playlist.addPattern(&rainbow);
    playlist.addPattern(&pulseGold);
}
