

#include "Arduino.h"
#include "cplusplus.h"

#include <FastLED.h>

#include "RadioHead.h"
#include "RH_RF69.h"

#include "RadioMessage.h"
#include "config.h"
#include "Playlist.h"
#include "kaiju_program.h"

// Encryption key must be 16 bytes "0123456789ABCDEF"
const char * const encryptionKey = "KaijuFlamboCore!";

CRGB frameBuffer[BUFFER_LENGTH];

Playlist playlist;

RH_RF69 radio;
const float RadioFrequency = 915.0;

void initializeRadio()
{
    radio.init();

    radio.setFrequency(RadioFrequency);
    radio.setEncryptionKey((uint8_t *) (encryptionKey));
    radio.setModemConfig(RH_RF69::GFSK_Rb19_2Fd38_4);

    pinMode(INPUT_PIN, INPUT_PULLUP);
}

void initializeLeds()
{
    pinMode(LED_INDICATOR_PIN, OUTPUT);

    // Set uninitialised LEDs to a faint grey
    memset8(frameBuffer, 1, BUFFER_LENGTH * sizeof(CRGB));

    FastLED.addLeds<WS2811, LED_DATA_PIN, RGB>(frameBuffer, BUFFER_LENGTH).setCorrection(Typical8mmPixel);
    FastLED.addLeds<WS2811, LED_DATA_PIN_SECOND_HALF, RGB>(frameBuffer + BUFFER_LENGTH / 2, BUFFER_LENGTH / 2).setCorrection(Typical8mmPixel);
    FastLED.show();

    addPatternsToPlaylist();
    playlist.currentPattern()->reset();
}

void setup()
{
    initializeRadio();

    initializeLeds();
}

// All times are in milliseconds
unsigned long lastFrameTime = 0;
unsigned long currentTime = 0;

uint8_t const txBuffer[sizeof(RadioMessage)] = { };
uint8_t *rxBuffer = const_cast<uint8_t*>(txBuffer);
uint8_t incomingPacketLength;
RadioMessage *message = reinterpret_cast<RadioMessage*>(const_cast<uint8_t*>(txBuffer));

bool isButtonHeld = false;

void transmitLoop()
{
    bool isButtonDown = (digitalRead(INPUT_PIN) == LOW);

    if (isButtonDown && !isButtonHeld) {
        playlist.cycleToNext();

        message->messageType = MessageType::SetPattern;
        message->payload = playlist.getCurrentPatternIndex();

        radio.send(txBuffer, RadioMessage::Size());
        radio.waitPacketSent();
    }

    isButtonHeld = isButtonDown;
}

inline void debugRadioReceiver(uint8_t value)
{
#if DEBUG_RADIO_RECEIVER
    digitalWrite(LED_INDICATOR_PIN, value);
#endif
}

void receiveLoop()
{
    debugRadioReceiver(LOW);

    if (radio.available()) {
        debugRadioReceiver(HIGH);

        // Set maximum receive size (will be overwritten with actual received packet length)
        incomingPacketLength = RadioMessage::Size();

        if (radio.recv(rxBuffer, &incomingPacketLength)) {
            playlist.goToPattern(message->payload);
        }
    }
}

inline void debugRenderTime(uint8_t value)
{
#if DEBUG_RENDER_TIME
    digitalWrite(LED_INDICATOR_PIN, value);
#endif
}

void render()
{
    Pattern* currentPattern = playlist.currentPattern();
    uint16_t timeSinceLastFrame = currentTime - lastFrameTime; // truncate

    debugRenderTime(HIGH);
    currentPattern->update(timeSinceLastFrame);
    currentPattern->draw(frameBuffer);
    debugRenderTime(LOW);

    FastLED.show();
}

void loop()
{
    lastFrameTime = currentTime;
    currentTime = millis();

    transmitLoop();
    receiveLoop();

    render();
}
