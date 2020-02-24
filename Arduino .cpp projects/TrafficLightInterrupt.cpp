/*
Description: Traffic Lights with interrupts
*/
#include <Arduino.h>
#define LED_RED 13
#define LED_YELLOW 12
#define LED_GREEN 11
//#define INTERRUPT_PIN 2
int button = 0;

void lightsOff();
void setup() {
	pinMode(LED_RED, OUTPUT);
	pinMode(LED_YELLOW, OUTPUT);
	pinMode(LED_GREEN, OUTPUT);
	digitalWrite(7, HIGH);
	//pinMode(INTERRUPT_PIN, INPUT_PULLUP);

	//attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), lightsOff, HIGH);
}

void loop()
{
	// Loop through each pin to blink it
	digitalWrite(LED_RED, HIGH);
	delay(500);
	digitalWrite(LED_RED, HIGH);
	digitalWrite(LED_YELLOW, HIGH);
	delay(500);
	digitalWrite(LED_RED, LOW);
	digitalWrite(LED_YELLOW, LOW);
	digitalWrite(LED_GREEN, HIGH);
	delay(500);
	digitalWrite(LED_GREEN, LOW);
	digitalWrite(LED_YELLOW, HIGH);
	delay(500);
	digitalWrite(LED_YELLOW, LOW);
	
	button = digitalRead(7);
	if(button == HIGH) {
		digitalWrite(LED_RED, HIGH);
		digitalWrite(LED_YELLOW, HIGH);
		digitalWrite(LED_GREEN, HIGH);
	}

	
}

void lightsOff() {
	digitalWrite(LED_RED, HIGH);
	digitalWrite(LED_YELLOW, HIGH);
	digitalWrite(LED_GREEN, HIGH);

}


