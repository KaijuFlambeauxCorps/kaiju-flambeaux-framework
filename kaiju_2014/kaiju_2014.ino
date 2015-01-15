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

#include "RadioHead.h"
#include "RH_RF69.h"

#include "RadioMessage.h"

// Encryption key must be 16 bytes
const char * const encryptionKey PROGMEM = "KyjuFlamboCore!"; // C string includes null-terminator, making this 16 bytes

CRGB frameBuffer[BUFFER_LENGTH];
BluePattern blue;
GreenPattern green;
RainbowFadePattern rainbow;
SparksPattern sparks(frameBuffer, NUM_LEDS, 24, 4, 10, 32, 96, 16);

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
    radio.setFrequency(915.0);

    Serial.print("Setting radio encryption key to \"");
    Serial.print(encryptionKey);
    Serial.println("\"...");
    radio.setEncryptionKey((unsigned char*) (encryptionKey));

    Serial.println("Initialising pins... ");
    pinMode(3, INPUT_PULLUP);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);

    isTransmitter = (digitalRead(3) == LOW);
    if (isTransmitter) {
        Serial.println("This module will transmit.");
    }
    else {
        Serial.println("This module will receive.");
    }

    Serial.print("Radio messages will be ");
    Serial.print(sizeof(RadioMessage));
    Serial.println(" bytes in length.");
}

void initializeLeds()
{
    // Set uninitialised LEDs to a faint grey
    memset8(frameBuffer, 1, BUFFER_LENGTH * sizeof(CRGB));

    FastLED.addLeds<WS2811, LED_PIN, GRB>(frameBuffer, BUFFER_LENGTH);
    FastLED.show();

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
unsigned long lastCycleTime = 0;
unsigned long lastFrameTime = 0;
unsigned long currentTime = 0;
const unsigned long cycleInterval = 1000;

uint8_t const radioBuffer[sizeof(RadioMessage)] = { };
RadioMessage *message = reinterpret_cast<RadioMessage*>(const_cast<uint8_t*>(radioBuffer));

void transmitLoop()
{
    if (currentTime - lastCycleTime > cycleInterval) {
        lastCycleTime = currentTime;

        playlist.cycleToNext();

        message->messageType = MessageType::SetPattern;
        message->payload = playlist.getCurrentPatternIndex();

        Serial.print("Sending radio message...");
        radio.send(radioBuffer, (unsigned char)sizeof(RadioMessage));
        radio.waitPacketSent();
        Serial.println(" Done.");
    }
}

void receiveLoop()
{

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

    if (isTransmitter) {
        transmitLoop();
    }
    else {
        receiveLoop();
    }

    render();
}
