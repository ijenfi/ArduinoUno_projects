/*
Description: Turn on green/red LEDs
*/

#include <Arduino.h>
#define GREENLED 11
#define REDLED 13
#define YELLOWLED 12

void greenLedOn() {
	digitalWrite(GREENLED, HIGH);

}

void redLedOn() {
	digitalWrite(REDLED, HIGH);
}

void yellowLedBlink(int delayTime) {
	digitalWrite(YELLOWLED, HIGH);
	delay(delayTime);
	digitalWrite(YELLOWLED, LOW);
	delay(delayTime);
}

void ledsOff() {
	digitalWrite(GREENLED, LOW);
	digitalWrite(REDLED, LOW);
}
