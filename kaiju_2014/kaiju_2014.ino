// THIS INCLUDE MUST BE FIRST
#include "kaiju_2014.h"
/////////////////////////////

#include "config.h"

#include "FastLED.h"

#include "PatternCycler.h"

#include "Patterns/Pattern.h"
#include "Patterns/BluePattern.h"
#include "Patterns/GreenPattern.h"

CRGB framebuffer[NUM_LEDS];
BluePattern blue;
GreenPattern green;

PatternCycler cycler;

void setup(){
    FastLED.addLeds<WS2811, LED_PIN, GRB>(framebuffer, NUM_LEDS);
    framebuffer[0] = CRGB(64, 0 , 0);
    FastLED.show();

    cycler.addPattern(&blue);
    cycler.addPattern(&green);
}

unsigned long previousMillis = 0;
unsigned long cycleInterval = 1000; // ms

unsigned char currentPattern = 0;

void loop() {
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis > cycleInterval) {
        previousMillis = currentMillis;

        cycler.cycleToNext();
    }

    cycler.currentPattern()->draw(framebuffer);

    FastLED.show();
}
