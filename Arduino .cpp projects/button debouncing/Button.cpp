/*
Description: debouncing in button
*/

#include <Arduino.h>
#include "Led.h"
#define BUTTON 2

volatile boolean lastButtonState = false;
volatile boolean ledState = true;
unsigned static long lastDebounceTime = 0;
unsigned static long debounceDelay = 50;

void pressButton(){
	int reading = digitalRead(BUTTON);
	int buttonState;
	if (reading != lastButtonState) {
		//reset the timer for the debouncer
		lastDebounceTime = millis();
	}
	if ((millis() - lastDebounceTime) > debounceDelay) {
		//the timer is set at the actual current state
		//if the button state has changed
		if (reading != buttonState) {
			buttonState = reading;
			//switch the state of the LEDs when the button is pressed
			if (buttonState == HIGH) {
				ledState = !ledState;
			}
		}
	}
	//to save last time reading
	lastButtonState = reading;

	if(reading == HIGH){
		yellowLedOn();
		delay(1000);
	}
	else{
		greenLedOn();
		delay(1000);
	}
}