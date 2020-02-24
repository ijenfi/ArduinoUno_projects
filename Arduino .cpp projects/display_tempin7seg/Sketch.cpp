/*
Description: UML diagram implementation of multiple functions and Arduino timer interrupts
*/

#include <Arduino.h>
#include "Led.h"
#include "Thermistor.h"
#include "Math.h"

#define GREENLED 11
#define REDLED 13
#define YELLOWLED 12
#define INTERRUPTLED 10
bool state = 0;

void setup() {
	pinMode(GREENLED, OUTPUT);
	pinMode(REDLED, OUTPUT);
	pinMode(YELLOWLED, OUTPUT);
	pinMode(INTERRUPTLED, OUTPUT);

	cli();
	//set timer1 interrupt at 1Hz
	TCCR1A = 0;// set entire TCCR1A register to 0
	TCCR1B = 0;// same for TCCR1B
	TCNT1  = 0;//initialize counter value to 0
	// set compare match register for 1hz increments
	OCR1A = 65535;// = (16*10^6) / (1*1024) - 1 (must be <65536)
	// turn on CTC mode
	TCCR1B |= (1 << WGM12);
	// Set CS10 and CS12 bits for 1024 prescaler
	TCCR1B |= (1 << CS12) | (1 << CS10);
	// enable timer compare interrupt
	TIMSK1 |= (1 << OCIE1A);
	sei();
}

void loop() {
	
	float celsius = getTemperature();
	if (celsius < 25 ) {
		greenLedOn();
	}
	if (celsius >= 25) {
		redLedOn();
	}
	delay(1000);

	ledsOff();
	
	delay(1000);

	int voltage = getVoltage();

	bool lsb = checkBit(voltage);

	for (int i = 0; i < 5; i++) {
		if (lsb == true) {
			yellowLedBlink(1000);
		}
		if (lsb == false) {
			yellowLedBlink(200);
		}
	}
	delay(1000);
}


ISR(TIMER1_COMPA_vect) {
	if (state == 0) {
		digitalWrite(INTERRUPTLED, LOW);
	}
	else {
		digitalWrite(INTERRUPTLED, HIGH);
	}
	
}
