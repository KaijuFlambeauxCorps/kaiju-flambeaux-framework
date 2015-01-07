// Do not remove the include below
#include "kaiju_2014.h"

#include "FastLED.h"

#include "Patterns/Pattern.h"
#include "Patterns/BluePattern.h"
#include "Patterns/GreenPattern.h"

CRGB framebuffer[4];
BluePattern blue;
GreenPattern green;

Pattern *patterns[2] = { &blue, &green };

void setup(){
    FastLED.addLeds<WS2811, 6, GRB>(framebuffer, 4);
    framebuffer[0] = CRGB(64, 0 , 0);
    FastLED.show();
}

unsigned long previousMillis = 0;
unsigned long interval = 1000; // ms

unsigned char currentPattern = 0;

void loop() {
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;

        framebuffer[0] = patterns[currentPattern]->GetColor();

        currentPattern++;
        currentPattern = currentPattern % 2;

        FastLED.show();
    }
}
