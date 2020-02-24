/*
Description: debouncing in button
*/

#include <Arduino.h>
#include "Led.h"
#include "Button.h"
#define RED1LED 13
#define RED2LED 12
#define GREENLED 11
#define YELLOWLED 10
#define RED3LED 9
#define RED4LED 8
#define BUTTON 2


void setup() {
	pinMode(GREENLED, OUTPUT);
	pinMode(RED1LED, OUTPUT);
	pinMode(YELLOWLED, OUTPUT);
	pinMode(RED2LED, OUTPUT);
	pinMode(RED3LED, OUTPUT);
	pinMode(RED4LED, OUTPUT);
	pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
		
		red1LedOn();
		delay(200);
		ledOff();
		delay(200);
		red2LedOn();
		delay(200);
		ledOff();
		delay(200);
		greenLedOn();
		delay(200);
		pressButton();
		red3LedOn();
		delay(200);
		red4LedOn();
		delay(200);
		ledOff();
		delay(200);
}
