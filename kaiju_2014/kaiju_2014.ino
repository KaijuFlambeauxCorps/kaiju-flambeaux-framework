// THIS INCLUDE MUST BE FIRST
#include "kaiju_2014.h"
/////////////////////////////

#include "config.h"

#include "FastLED.h"

#include "Patterns/Pattern.h"
#include "Patterns/BluePattern.h"
#include "Patterns/GreenPattern.h"
#include "Patterns/RainbowFadePattern.h"
#include "Patterns/SparksPattern.h"
#include "Playlist.h"

CRGB framebuffer[BUFFER_LENGTH];
BluePattern blue;
GreenPattern green;
RainbowFadePattern rainbow;
SparksPattern sparks(framebuffer, BUFFER_LENGTH, 4, 10, 64, 255, 16);

Playlist playlist;

void setup(){
    // Set uninitialised LEDs to a faint grey
    memset8(framebuffer, 1, BUFFER_LENGTH * sizeof(CRGB));

    FastLED.addLeds<WS2811, LED_PIN, GRB>(framebuffer, BUFFER_LENGTH);
    FastLED.show();

    playlist.addPattern(&blue);
    playlist.addPattern(&green);
    playlist.addPattern(&rainbow);
    playlist.addPattern(&sparks);
}

// All times are in milliseconds
unsigned long lastCycleTime = 0;
unsigned long lastFrameTime = 0;
unsigned long currentTime = 0;
unsigned long cycleInterval = 1000;

void loop() {
	lastFrameTime = currentTime;
    currentTime = millis();

    if(currentTime - lastCycleTime > cycleInterval) {
        lastCycleTime = currentTime;

        playlist.cycleToNext();
    }

	Pattern* currentPattern = playlist.currentPattern();

	uint16_t timeSinceLastFrame = lastFrameTime - currentTime; // truncate

	currentPattern->update(timeSinceLastFrame);
	currentPattern->draw(framebuffer);

    FastLED.show();
}
