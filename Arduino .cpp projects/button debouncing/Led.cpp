/*
Description: lights functions
*/
#include <Arduino.h>
#define RED1LED 13
#define RED2LED 12
#define GREENLED 11
#define YELLOWLED 10
#define RED3LED 9
#define RED4LED 8

void ledOff(){
	digitalWrite(RED1LED, LOW);
	digitalWrite(RED2LED, LOW);
	digitalWrite(GREENLED, LOW);
	digitalWrite(YELLOWLED, LOW);
	digitalWrite(RED3LED, LOW);
	digitalWrite(RED4LED, LOW);
}

void red1LedOn(){
	digitalWrite(RED1LED, HIGH);
}

void red2LedOn(){
	digitalWrite(RED2LED, HIGH);
}

void red3LedOn(){
	digitalWrite(RED3LED, HIGH);
}

void red4LedOn(){
	digitalWrite(RED4LED, HIGH);
}

void greenLedOn(){
	digitalWrite(GREENLED, HIGH);
}

void yellowLedOn(){
	digitalWrite(YELLOWLED, HIGH);
}