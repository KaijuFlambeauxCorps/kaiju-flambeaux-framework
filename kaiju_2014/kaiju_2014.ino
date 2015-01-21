// THIS INCLUDE MUST BE FIRST
#include "kaiju_2014.h"
/////////////////////////////

#include "config.h"

#include "FastLED.h"

#include "Patterns/Pattern.h"
#include "Patterns/GradientPattern.h"
#include "Patterns/PulsingSaturationPattern.h"
#include "Patterns/BluePattern.h"
#include "Patterns/GreenPattern.h"
#include "Patterns/RainbowFadePattern.h"
#include "Patterns/SparksPattern.h"
#include "Playlist.h"

#include "RadioHead.h"
#include "RH_RF69.h"

#include "RadioMessage.h"

// Encryption key must be 16 bytes
const char * const encryptionKey PROGMEM = "KyjuFlamboCore!"; // C string includes null-terminator, making this 16 bytes

CRGB frameBuffer[BUFFER_LENGTH];
GradientPattern gradient(RainbowStripeColors_p);
PulsingSaturationPattern pulseRed(0, 96, 1000);
PulsingSaturationPattern pulseGreen(HUE_MAX_RAINBOW / 3, 96, 700);
PulsingSaturationPattern pulseBlue(HUE_MAX_RAINBOW / 3 * 2, 96, 450);
BluePattern blue;
GreenPattern green;
RainbowFadePattern rainbow;
SparksPattern sparks(frameBuffer, NUM_LEDS, 24, 3, 10, 96, 255, 20);

Playlist playlist;

RH_RF69 radio;
const float RadioFrequency = 915.0;
bool isTransmitter;

void initializeRadio()
{
    Serial.begin(57600);
    Serial.println("Initialising radio...");
    radio.init();

    Serial.print("Setting radio frequency to ");
    Serial.print(RadioFrequency);
    Serial.println("MHz...");
    radio.setFrequency(RadioFrequency);

    Serial.print("Setting radio encryption key to \"");
    Serial.print(encryptionKey);
    Serial.println("\"...");
    radio.setEncryptionKey((unsigned char*) (encryptionKey));

    Serial.println("Setting modem config...");
    radio.setModemConfig(RH_RF69::GFSK_Rb19_2Fd38_4);

    Serial.println("Initialising pins... ");
    pinMode(INPUT_PIN, INPUT_PULLUP);

    Serial.print("Radio messages will be ");
    Serial.print(RadioMessage::Size());
    Serial.println(" bytes in length.");
}

void initializeLeds()
{
    pinMode(LED_INDICATOR_PIN, OUTPUT);

    // Set uninitialised LEDs to a faint grey
    memset8(frameBuffer, 1, BUFFER_LENGTH * sizeof(CRGB));

    FastLED.addLeds<WS2811, LED_DATA_PIN, GRB>(frameBuffer, BUFFER_LENGTH).setCorrection(Typical8mmPixel);
    FastLED.addLeds<WS2811, LED_DATA_PIN_SECOND_HALF, GRB>(frameBuffer + BUFFER_LENGTH / 2, BUFFER_LENGTH / 2).setCorrection(Typical8mmPixel);
    FastLED.show();

    playlist.addPattern(&gradient);
    playlist.addPattern(&pulseRed);
    playlist.addPattern(&pulseGreen);
    playlist.addPattern(&pulseBlue);
    playlist.addPattern(&blue);
    playlist.addPattern(&green);
    playlist.addPattern(&rainbow);
    playlist.addPattern(&sparks);
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

        Serial.print("Instructing other units to change to pattern ");
        Serial.print(message->payload);
        Serial.print("...");
        radio.send(txBuffer, RadioMessage::Size());
        radio.waitPacketSent();
        Serial.println(" Done.");
    }

    isButtonHeld = isButtonDown;
}

void receiveLoop()
{
    digitalWrite(LED_INDICATOR_PIN, LOW);

    if (radio.available()) {
        digitalWrite(LED_INDICATOR_PIN, HIGH);
        Serial.println("\r\nRadio message available! ");

        // Set maximum receive size (will be overwritten with actual received packet length)
        incomingPacketLength = RadioMessage::Size();

        if (radio.recv(rxBuffer, &incomingPacketLength)) {
            Serial.print("Message type: ");
            Serial.print(message->messageType);
            Serial.print(", payload: ");
            Serial.println(message->payload);

            playlist.goToPattern(message->payload);
        }
    }
}

void render()
{
    Pattern* currentPattern = playlist.currentPattern();
    uint16_t timeSinceLastFrame = currentTime - lastFrameTime; // truncate

    currentPattern->update(timeSinceLastFrame);
    currentPattern->draw(frameBuffer);

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
