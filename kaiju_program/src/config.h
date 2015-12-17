/*
 * config.h
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#ifndef CONFIG_H_
#define CONFIG_H_

// Available pins on Flambeaux Board v1.3 are:
// 4, 5, 6, 7, 11, 12, A2

// [Labels]
// 4: SW
// 6: OUT


#define BUFFER_LENGTH 100 // >100LEDs unsupported
#define NUM_LEDS 100
#define LED_DATA_PIN 6
#define LED_DATA_PIN_SECOND_HALF 7
#define INPUT_PIN 4
#define LED_INDICATOR_PIN 9 // Hardwired on the board

#endif /* CONFIG_H_ */
