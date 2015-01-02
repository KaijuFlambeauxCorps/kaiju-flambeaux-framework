#include "FastLED.h"

CRGB framebuffer[1];

void kaiju_setup(){
    FastLED.addLeds<WS2811, 6, GRB>(framebuffer, 1);
}

void kaiju_loop() {
    framebuffer[0] = CRGB::White;
    FastLED.show();
    delay(30);

    framebuffer[0] = CRGB::Black;
    FastLED.show();
    delay(30);
}
