// Do not remove the include below
#include "kaiju_2014.h"

#include "FastLED.h"

CRGB framebuffer[1];

void setup(){
    FastLED.addLeds<WS2811, 6, GRB>(framebuffer, 1);
}

unsigned long previousMillis = 0;
unsigned long interval = 1000; // ms

void loop() {
    unsigned long currentMillis = millis();

    if(currentMillis - previousMillis > interval) {
        previousMillis = currentMillis;

        if (framebuffer[0].r == 64) {
            framebuffer[0] = CRGB(0, 64, 64);
        }
        else
        {
            framebuffer[0] = CRGB(64, 0, 0);
        }
    }

    FastLED.show();
}
