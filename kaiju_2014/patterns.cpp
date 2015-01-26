/*
 * patterns.cpp
 *
 *  Created on: 26 Jan 2015
 *      Author: tully
 */

#include "config.h"

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
GradientPattern rainbowGradient(RainbowColors_p, 8, 33);
GradientPattern forestGradient(ForestColors_p, 8, 33);
GradientPattern lavaGradient(LavaColors_p, 8, 33);
PulsingSaturationPattern pulsePurple(HUE_MAX_RAINBOW / 6 * 5, 96, 1000);
PulsingSaturationPattern pulseGreen(HUE_MAX_RAINBOW / 3, 96, 700);
PulsingSaturationPattern pulseGold(HUE_MAX_RAINBOW / 6, 96, 450);
RainbowFadePattern rainbow;
SparksPattern sparks(frameBuffer, NUM_LEDS, 24, 3, 10, 96, 128, 20);

void addPatternsToPlaylist(Playlist* playlist)
{
    playlist->addPattern(&mardiGrasGradient);
    playlist->addPattern(&rainbowStripeGradient);
    playlist->addPattern(&rainbowGradient);
    playlist->addPattern(&forestGradient);
    playlist->addPattern(&lavaGradient);
    playlist->addPattern(&pulsePurple);
    playlist->addPattern(&pulseGreen);
    playlist->addPattern(&pulseGold);
    playlist->addPattern(&rainbow);
    playlist->addPattern(&sparks);
}
