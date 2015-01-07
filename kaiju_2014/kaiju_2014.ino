// THIS INCLUDE MUST BE FIRST
#include "kaiju_2014.h"
/////////////////////////////

#include "config.h"

#include "FastLED.h"

#include "Patterns/Pattern.h"
#include "Patterns/BluePattern.h"
#include "Patterns/GreenPattern.h"
#include "Playlist.h"

CRGB framebuffer[BUFFER_LENGTH];
BluePattern blue;
GreenPattern green;

Playlist playlist;

void setup(){
    // Set uninitialised LEDs to a faint grey
    memset8(framebuffer, 1, BUFFER_LENGTH * sizeof(CRGB));

    FastLED.addLeds<WS2811, LED_PIN, GRB>(framebuffer, BUFFER_LENGTH);
    FastLED.show();

    playlist.addPattern(&blue);
    playlist.addPattern(&green);
}

unsigned long previousMillis = 0;
unsigned long cycleInterval = 1000; // ms

unsigned char currentPattern = 0;

void loop() {
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis > cycleInterval) {
        previousMillis = currentMillis;

        playlist.cycleToNext();
    }

    playlist.currentPattern()->draw(framebuffer);

    FastLED.show();
}
